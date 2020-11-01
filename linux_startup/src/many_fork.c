#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    fork();
    printf("hello\n");
    fork();
    printf("hello\n");

    pid = getpid();

    while(1) {
        printf("process %d is sleeping...\n", pid);
        sleep(3);
    }
}
