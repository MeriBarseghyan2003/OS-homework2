#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    if (fork() == 0) {
        execl("/bin/ls", "ls", NULL);
    } else {
        if (fork() == 0) {
            execl("/bin/date", "date", NULL);
        } else {
            wait(NULL);
            wait(NULL);
            printf("Parent process done\n");
        }
    }

    return 0;
}