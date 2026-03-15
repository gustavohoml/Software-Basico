#include <stdio.h>

void num2string(char *s, int num, int base) {

}

int is_little(void) {
  int c = 1;
  unsigned char *p = (unsigned char *)&c;

  if (*p == 1) 
    return 1;
  else 
    return 0;
}

int main() {
    // switch (is_little()) {
    //    case 1: 
    //        printf("Maquina Little-Endian \n");    
    //        break;
    //    case 0:
    //        printf("Maquina Big-Endian \n");    
    //        break;     
    // }
    char *buffer[10];
    num2string(buffer, 10, 10);

    return 0;
}