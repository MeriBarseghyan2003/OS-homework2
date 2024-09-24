#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t pid1 = fork();

    if (pid1 == -1) {
        perror("First fork failed");
        exit(1);
    } else if (pid1 == 0) {
        printf("First child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
    } else {
        printf("Parent after first fork (PID: %d, First child PID: %d)\n", getpid(), pid1);
    }

    pid_t pid2 = fork();

    if (pid2 == -1) {
        perror("Second fork failed");
        exit(1);
    } else if (pid2 == 0) {
        printf("Second child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
    } else {
        printf("Parent after second fork (PID: %d, Second child PID: %d)\n", getpid(), pid2);
    }

    pid_t pid3 = fork();

    if (pid3 == -1) {
        perror("Third fork failed");
        exit(1);
    } else if (pid3 == 0) {
        printf("Third child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
    } else {
        printf("Parent after third fork (PID: %d, Third child PID: %d)\n", getpid(), pid3);
    }

    sleep(1);

    return 0;
}