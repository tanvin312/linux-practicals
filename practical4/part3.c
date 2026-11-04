#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
    }
    else if (pid == 0) {
        printf("Child process. PID = %d\n", getpid());
    }
    else {
        wait(NULL);
        printf("Parent process. PID = %d\n", getpid());
    }

    return 0;
}