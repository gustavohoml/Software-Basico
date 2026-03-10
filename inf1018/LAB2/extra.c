#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%d ", *p1);
    p1++;
  }
}

void is_little(void) {
    unsigned int i = 1;
    int n = 4;
    unsigned char *pi = &i;
    

    while (n--) {
        printf("%d ", *pi);
        pi++;
    }
}

int main() {
    is_little();
    //switch (is_little()) {
    //    case 1: 
    //        printf("Maquina Little-Endian");    
    //        break;
    //    case 0:
    //        printf("Maquina Big-Endian");    
    //        break;     
    //}

    return 0;
}