#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ignore(int signum) {
    printf("ignore signal %d\n", signum);
}

int main(int argc, char *argv[]) {
    int signum;

    if (argc < 2) {
        printf("usage: ./devide_zero flag\n");
        printf("flag:\n");
        printf("    0 -- do not ignore SIGFPE\n");
        printf("    1 -- ignore SIGFPE\n");
        return 1;
    }

    if (atoi(argv[1]) == 1) {
        if (signal(SIGFPE, ignore) == SIG_ERR) {
            printf("cannot catch signal %d\n", SIGFPE);
            return 1;
        }
    }

    printf("2020/0=%d\n", 2020/0);

    return 0;
}
