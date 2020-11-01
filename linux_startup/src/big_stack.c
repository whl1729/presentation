#include <stdio.h>

#define LEN 1047070

int main() {
    long arr[LEN];
    int i;

    for (i = 0; i < LEN; i++) {
        arr[i] = i;
    }

    printf("hello world\n");
    return 0;
}
