#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void ignore(int signum) {
    printf("ignore signal %d\n", signum);
}

int main(int argc, char *argv[]) {
    int i, signum;
    pid_t pid = getpid();

    for (i = 1; i < argc; i++) {
        signum = atoi(argv[i]);
        if (signal(signum, ignore) == SIG_ERR) {
            printf("cannot catch signal %d\n", signum);
            return 1;
        }
    }

    while (1) {
        printf("pid %d: sleeping for %d seconds...\n", pid, i * 3);
        sleep(3);
        i++;
    }

    return 0;
}

