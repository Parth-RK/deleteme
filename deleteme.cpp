#include <iostream>
#include <string>
#include <limits.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

std::string getExecutablePath() {
#ifdef _WIN32
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    return std::string(buffer);
#else
    char buffer[PATH_MAX];
    readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    return std::string(buffer);
#endif
}

int main() {
    std::string exe_file = getExecutablePath();
    std::string src_file = __FILE__;
    remove(src_file.c_str());
    remove(exe_file.c_str());
    return 0;
}