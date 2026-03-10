#include <ctype.h>
#include <stdio.h>
 
int is_digit(char c) {
    return (((c >= 'a') && (c <= 'z')) ? 1 : 0);
}

int string2num (char *s, int base) {
    int a = 0;
    for (; *s; s++) {
        //printf("%c \n", *s); // isso imprime o digito atual
        //printf("%s \n", s); // isso imprime a string
        if (is_digit(*s))
            a = a*base + (*s - 'a');
        else
            a = a*base + (*s - '0');
    }
    return a;
}

int main (void) {
    printf("%d\n", string2num("1a", 16));
    printf("%d\n", string2num("a09b", 16));
    printf("%d\n", string2num("z09b", 36));

    return 0;
}