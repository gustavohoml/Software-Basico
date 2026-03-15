#include <stdio.h>

unsigned char switch_byte(unsigned char x) {
    unsigned int aux = x << 4;
    x = x >> 4;
    x = x | aux;
    return x;
}

unsigned char rotate_left(unsigned char x, int n) {
    int cont = 0;
    while (cont < n) {
        unsigned char valor = x >> 7;
        x = x << 1;
        x = x | valor;
        cont++;
    }
    return x;
}

int main(void)  {
    printf("\nTESTES ITEM A: \n");
    unsigned char exemplo = 0xAB;
    printf("%X vira %X \n\n", exemplo, switch_byte(0xAB));
    
    printf("TESTES ITEM B: \n");
    exemplo = 0x61;
    printf("exemplo: %X \n", exemplo);
    printf("%d bits: %X \n", 1, rotate_left(exemplo, 1));
    printf("%d bits: %X \n", 2, rotate_left(exemplo, 2));
    printf("%d bits: %X \n\n", 7, rotate_left(exemplo, 7));


    return 0;
}