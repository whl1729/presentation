#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void ignore(int signum) {
    printf("ignore signal %d\n", signum);
}

int main() {
    if (signal(SIGABRT, ignore) == SIG_ERR) {
        printf("cannot catch signal %d\n", SIGABRT);
        return 1;
    }

    abort();
    printf("after abort\n");
}
