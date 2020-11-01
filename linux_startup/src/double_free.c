#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void ignore(int signum) {
    printf("ignore signal %d\n", signum);
}

int main(int argc, char *argv[]) {
    int *arr;
    int i;

    if (argc < 2) {
        printf("usage: ./double_free flag\n");
        printf("flag:\n");
        printf("    0 -- do not ignore SIGABRT\n");
        printf("    1 -- ignore SIGABRT\n");
        return 1;
    }

    if (atoi(argv[1]) == 1) {
        if (signal(SIGABRT, ignore) == SIG_ERR) {
            printf("cannot catch signal %d\n", SIGABRT);
            return 1;
        }
    }

    arr = malloc(sizeof(int) * 5);

    for (i = 0; i < 100; i++) {
        free(arr);
    }

    return 0;
}
