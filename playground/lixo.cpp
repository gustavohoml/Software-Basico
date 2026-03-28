#include <stdio.h>

char nums[] = {10, -21, -30, 45};

int main() {
    int i = 0;
    char *p;
    while (i != 4) {
        printf("%d\n", *p);
        i += 1;
        p += 1;
    }

    return 0;
}