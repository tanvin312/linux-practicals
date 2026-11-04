#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;

    /* Part 1: Memory totals via the sysinfo() system call */
    if (sysinfo(&info) == -1) {
        perror("sysinfo");
        return 1;
    }

    unsigned long long unit = info.mem_unit;
    unsigned long long total = info.totalram * unit;
    unsigned long long freem = info.freeram * unit;
    unsigned long long used = total - freem;

    printf("===== Memory Information (via sysinfo()) =====\n");
    printf("Total (configured) : %llu MiB\n", total / (1024 * 1024));
    printf("Free               : %llu MiB\n", freem / (1024 * 1024));
    printf("Used               : %llu MiB\n", used / (1024 * 1024));

    /* Part 2: Detailed figures by reading /proc/meminfo as text */
    printf("\n===== Memory Information (via /proc/meminfo) =====\n");

    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char line[256];

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "MemTotal", 8) == 0 ||
            strncmp(line, "MemFree", 7) == 0 ||
            strncmp(line, "MemAvailable", 12) == 0) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}
