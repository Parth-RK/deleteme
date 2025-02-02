#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #include <limits.h>
    #include <libgen.h>
#endif

int main(int argc, char *argv[]) {
    char exe_path[PATH_MAX];
    char src_path[PATH_MAX];

    // Get the absolute path of the executable
    if (realpath(argv[0], exe_path) == NULL) {
        perror("Failed to resolve executable path");
        return 1;
    }

    // Get the absolute path of the source file
    if (realpath(__FILE__, src_path) == NULL) {
        perror("Failed to resolve source file path");
        return 1;
    }

#ifdef _WIN32
    // Windows: Use a separate process to delete files after exit
    char cmd[512];
    snprintf(cmd, sizeof(cmd), "cmd /c timeout 1 & del \"%s\" \"%s\"", exe_path, src_path);
    system(cmd);
#else
    // Linux/macOS: Delete using a background process
    char cmd[512];
    snprintf(cmd, sizeof(cmd), "sleep 1; rm \"%s\" \"%s\" &", exe_path, src_path);
    system(cmd);
#endif

    return 0;
}
