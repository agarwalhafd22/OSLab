#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("Child process creation failed\n");
        return 1;
    } else if (pid > 0) {
        printf("In parent process\n");
        printf("PID: %d\n", getpid());
        printf("Child's PID: %d\n", pid);
    } else {
        printf("In child process\n");
        printf("PID: %d\n", getpid());
        printf("Parent's PID: %d\n", getppid());
    }

    return 0;
}

