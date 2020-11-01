#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void ignore(int signum) {
    printf("ignore signal %d\n", signum);
}

int main(int argc, char *argv[]) {
    int *ptr = NULL;

    if (argc < 2) {
        printf("usage: ./null_ptr flag\n");
        printf("flag:\n");
        printf("    0 -- do not ignore SIGSEGV\n");
        printf("    1 -- ignore SIGSEGV\n");
        return 1;
    }

    if (atoi(argv[1]) == 1) {
        if (signal(SIGSEGV, ignore) == SIG_ERR) {
            printf("cannot catch signal %d\n", SIGSEGV);
            return 1;
        }
    }

    printf("*ptr=%d\n", *ptr);
    return 0;
}
