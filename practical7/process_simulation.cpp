#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        cout << "Fork failed" << endl;
        return 1;
    }

    if (pid == 0) {
        cout << "Child process PID: " << getpid() << endl;
        execlp("ls", "ls", "-l", (char *)NULL);
        exit(1);
    }
    else {
        cout << "Parent PID: " << getpid()
             << ", Child PID: " << pid << endl;

        wait(NULL);
    }

    return 0;
}
