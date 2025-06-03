#ifndef MEMORYSCANNER_H
#define MEMORYSCANNER_H

#include <windows.h>
#include <QObject>
#include <QString>
#include <QSet>
#include <tlhelp32.h>
#include <psapi.h>
#include <vector>
#include <stdexcept>

class MemoryScanner
{
private:
    static std::vector<std::pair<uintptr_t, size_t>> GetRegionInformation(HANDLE hProcess);
public:
    MemoryScanner();
    std::vector<std::pair<QString, DWORD>> GetAllProcesses();
    std::vector<std::pair<uintptr_t, int>> Find(HANDLE hProcess, int targetValue, uintptr_t startAddress, uintptr_t endAddress);
    std::vector<std::pair<uintptr_t, int>> Filter(HANDLE hProcess, const std::vector<std::pair<uintptr_t, int>> addressFounded, int targetValue);
    void Write(HANDLE hProcess, std::vector<std::pair<uintptr_t, int>> addressFounded);
};

#endif // MEMORYSCANNER_H
