
#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>

int main() {
    struct utsname sys_info;

    /* Part 1: Kernel information via uname() system call */
    if (uname(&sys_info) == -1) {
        perror("uname");
        return 1;
    }

    printf("===== Kernel Information (via uname()) =====\n");
    printf("System Name    : %s\n", sys_info.sysname);
    printf("Node Name      : %s\n", sys_info.nodename);
    printf("Kernel Release : %s\n", sys_info.release);
    printf("Kernel Version : %s\n", sys_info.version);
    printf("Machine        : %s\n", sys_info.machine);

    /* Part 2: CPU information via /proc/cpuinfo */
    printf("\n===== CPU Information (via /proc/cpuinfo) =====\n");

    FILE *fp = fopen("/proc/cpuinfo", "r");

    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char line[256];

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "model name", 10) == 0 ||
            strncmp(line, "cpu MHz", 7) == 0 ||
            strncmp(line, "cache size", 10) == 0 ||
            strncmp(line, "cpu cores", 9) == 0) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}
