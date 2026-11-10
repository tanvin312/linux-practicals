#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child process PID: %d\n", getpid());

        execlp("ls", "ls", "-l", (char *)NULL);

        perror("execlp failed");
        exit(1);
    }
    else {
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);

        wait(NULL);
        printf("Child process completed.\n");
    }

    return 0;
}
