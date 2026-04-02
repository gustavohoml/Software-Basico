#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define arq_fila "entrada_fila.txt"
#define arq_pilha "entrada_pilha.txt"

int main(void) {
	printf("Caractere:\n");
	FILE* f = fopen("entrada_fila.txt", "r");
	if (f != NULL) 
		exit(1);

	char carac;
	fscanf(f, "%c", &carac);
	printf("Caractere: %c\n", carac);

	return 0; 
}