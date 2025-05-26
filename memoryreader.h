#ifndef MEMORYREADER_H
#define MEMORYREADER_H

#include <windows.h>
#include <psapi.h>
#include <vector>
#include <QException>

class MemoryReader
{
private:
    MemoryReader();
    static std::vector<std::pair<uintptr_t, size_t>> GetRegionInformation(HANDLE hProcess);

public:
    static std::vector<std::pair<uintptr_t, int>> Find(HANDLE hProcess, int targetValue, uintptr_t startAddress, uintptr_t endAddress);
    static std::vector<std::pair<uintptr_t, int>> Filter(HANDLE hProcess, const std::vector<std::pair<uintptr_t, int>> addressFounded, int targetValue);
    static void Write(HANDLE hProcess, const std::vector<std::pair<uintptr_t, int>> addressFounded);
};

#endif // MEMORYREADER_H
