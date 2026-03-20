#include <stdio.h>
#define TAM_MAX 100

void num2string(char *s, int num, int base) {
    char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char temp[TAM_MAX];
    int i = 0;

    if (base < 2 || base > 36) {
        s[0] = '\0'; // Base inválida
        return;
    }

    if (num == 0) {
        s[0] = '0';
        s[1] = '\0';
        return;
    }

    while (num > 0 && i < TAM_MAX - 1) {
        temp[i++] = digits[num % base];
        num /= base;
    }
    temp[i] = '\0';

    // Inverter a string resultante
    for (int j = 0; j < i; j++) {
        s[j] = temp[i - j - 1];
    }
    s[i] = '\0';
}

int is_little(void) {
  int c = 1;
  unsigned char *p = (unsigned char *)&c;

  return (*p == 1) ? 1 : 0;
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

    char buffer1[TAM_MAX];
    num2string(buffer1, 10, 10);
    printf("Número 10 em base 10: %s\n", buffer1);

    char buffer2[TAM_MAX];
    num2string(buffer2, 10, 2);
    printf("Número 10 em base 2: %s\n", buffer2);
    
    char buffer3[TAM_MAX];
    num2string(buffer3, 10, 16);
    printf("Número 10 em base 16: %s\n", buffer3);

    return 0;
}