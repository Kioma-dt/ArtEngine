#include "memoryscanner.h"

MemoryScanner::MemoryScanner() {}

std::vector<std::pair<uintptr_t, size_t> > MemoryScanner::GetRegionInformation(HANDLE hProcess)
{
    std::vector <std::pair<uintptr_t, size_t>> base_size;

    MEMORY_BASIC_INFORMATION info;
    uintptr_t address = 0;
    while (VirtualQueryEx(hProcess, (LPCVOID)address, &info, sizeof(info)) == sizeof(info)) {
        if (info.State == MEM_COMMIT && (info.Protect == PAGE_READWRITE || info.Protect == PAGE_WRITECOPY)) {
            base_size.push_back(std::make_pair(reinterpret_cast<uintptr_t>(info.BaseAddress), info.RegionSize));
        }
        address += info.RegionSize;
    }

    return base_size;
}

std::vector<std::pair<QString, DWORD> > MemoryScanner::GetAllProcesses()
{
    std::vector<std::pair<QString, DWORD>> processes;
    QSet<QString> processNames;

    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return processes;
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hSnapshot, &pe)) {
        do {
            QString name = QString::fromWCharArray(pe.szExeFile);
            DWORD ID = pe.th32ProcessID;
            if(!processNames.contains(name)){
                processes.insert(processes.begin(), std::make_pair(name, ID));
                processNames.insert(name);
            }

        } while (Process32Next(hSnapshot, &pe));
    }

    CloseHandle(hSnapshot);
    return processes;
}

std::vector<std::pair<uintptr_t, int>> MemoryScanner::Find(HANDLE hProcess, int targetValue, uintptr_t startAddress, uintptr_t endAddress)
{
    SIZE_T bytesRead;
    std::vector <std::pair<uintptr_t, size_t>> regionArray = GetRegionInformation(hProcess);
    std::vector<std::pair<uintptr_t, int>> addressFounded;


    for (auto region : regionArray) {
        if (region.first + region.second < startAddress) {
            continue;
        }
        if (region.first > endAddress) {
            break;
        }
        BYTE* buffer = new BYTE[region.second];
        if (ReadProcessMemory(hProcess, (LPCVOID)region.first, buffer, region.second, &bytesRead)) {
            for (size_t i = 0; i < bytesRead - sizeof(int); i++) {
                if (*(reinterpret_cast<int*>(buffer + i)) == targetValue) {
                    addressFounded.push_back(std::make_pair(region.first + i, targetValue));
                }
            }
        }
        delete[] buffer;
    }

    return addressFounded;
}

std::vector<std::pair<uintptr_t, int> > MemoryScanner::Filter(HANDLE hProcess, const std::vector<std::pair<uintptr_t, int>> addressFounded, int targetValue)
{
    int value;
    SIZE_T bytesRead;


    std::vector<std::pair<uintptr_t, int>> addressFiltered;
    for (auto address : addressFounded) {
        if (ReadProcessMemory(hProcess, (LPCVOID)address.first, &value, sizeof(value), &bytesRead)) {
            if (value == targetValue) {
                addressFiltered.push_back(std::make_pair(address.first, targetValue));
            }
        }
    }

    return addressFiltered;
}

void MemoryScanner::Write(HANDLE hProcess, const std::vector<std::pair<uintptr_t, int> > addressFounded)
{
    for(auto [address, value] : addressFounded){
        int new_value = value;
        if(!WriteProcessMemory(hProcess, (LPVOID)address, &new_value, sizeof(new_value), NULL)){
            throw std::runtime_error("Не удалось записать");
        }
    }
}
