#include <stdio.h>

struct X1 {
  char c1;
  int i;
  char c2;
} x1 = {0xa1, 0xb1b2b3b4, 0xc1};

struct X2 {
  long l;
  char c;
} x2 = {0xa1a2a3a4a5a6a7a8, 0xb1};

struct X3 {
  int i;
  char c1;
  char c2;
} x3 = {0xa1a2a3a4, 0xb1, 0xc1};

struct X4 {
  struct X2 x;
  char c;
} x4 = {{0xa1a2a3a4a5a6a7a8, 0xb1}, 0xc1};

struct X5 {
  char c1;
  char c2;
  char c3;
} x5 = {0x21, 0x22, 0x23};

struct X6 {
  short s1;
  int i;
  char c[3];
  short s2;
} x6 = {0xa1a2, 0xb1b2b3b4, {0xc1, 0xc2, 0xc3}, 0xd1d2};

union U1 {
  int i;
  char c[5];
} u1 = {0xa1a2a3a4}; 

union U2 {
  short s;
  char c[5];
} u2 = {0xa1a2};

void dump (void *p, int n) {
    unsigned char *p1 = p;
    while (n--) {
      printf("%p - %02x\n", p1, *p1);
      p1++;
    }
}

int main (void) {
    printf ("tamanho: %ld\n", sizeof(u2));
    printf ("x: \n");
    dump (&u2, sizeof(u2));

    return 0;
}