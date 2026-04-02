#include <stdio.h>
int nums[4] = {65, -105, 111, 34};
int main (void) {
  int i;
  int s = 0;
  for (i=0;i<4;i++)
    s = s+nums[i];
  printf ("soma = %d\n", s);
  return 0;
}

/*
#include <stdio.h>

char S2[] = { 65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0 };

int main(void) {
    char* pc = S2;
    while (*pc) {
        if ((*pc == '{') || (*pc == '}')) {
            *pc++;
            continue;
        }
        printf("%c", *pc++);
    }
    printf("\n");
    return 0;
}
*/