#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifdef _WIN32
    #include <windows.h>
    #define DELETE_CMD "cmd /c timeout 1 & del \"%s\" \"%s\""
#else
    #include <unistd.h>
    #define DELETE_CMD "sleep 1; rm \"%s\" \"%s\" &"
#endif

int main(int argc, char *argv[]) {
    char exe[PATH_MAX], src[PATH_MAX], cmd[16384];

    if (!realpath(argv[0], exe) || !realpath(__FILE__, src)) return 1;
    snprintf(cmd, sizeof(cmd), DELETE_CMD, exe, src);
    system(cmd);

    return 0;
}

// Most simple approach would be:
//works on linux

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <limits.h>

// int main(int argc, char *argv[]) {
//     char exe[PATH_MAX], src[PATH_MAX];
//     realpath(argv[0], exe);
//     realpath(__FILE__, src);
//     remove(exe);
//     remove(src);
//     return 0;
// }
