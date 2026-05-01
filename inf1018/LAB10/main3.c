#include <stdio.h>
struct X {
  int val1;
  int val2;
};

void boo (struct X *px, int n, int val);

int f(int i, int v) {
  if (i >= v)
    return i;
  else
    return v;
}

int main (void) {
  struct X x[6] = {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}};
  int i;

  printf("Antes: ");
  for (i=0; i < 6; i++)
    printf("{%d,%d} ",x[i].val1, x[i].val2);
  boo(x,6,3);
  printf("\nDepois: ");
  for (i=0; i < 6; i++)
    printf("{%d,%d} ",x[i].val1, x[i].val2);
  printf("\n");
  return 0;
}