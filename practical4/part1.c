#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    printf("Hello from process. PID = %d\n", getpid());
    return 0;
}
