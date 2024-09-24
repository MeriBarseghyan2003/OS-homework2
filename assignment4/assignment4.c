#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    if (fork() == 0) {
        execl("/bin/grep", "grep", "main", "test.txt", NULL);
    } else {
        wait(NULL);
        printf("Parent process done\n");
    }

    return 0;
}