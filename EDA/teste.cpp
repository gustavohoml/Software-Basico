#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define arq_fila "entrada_fila.txt"
#define arq_pilha "entrada_pilha.txt"
//#pragma warning(disable : 4996)

typedef struct lista Lista;

struct lista {
	int info;
	lista* prox;
};	

Lista* fila_cria(void) {
	Lista* f = (Lista*)malloc(sizeof(Lista));
	if (f == NULL)
		exit(3);
	f->info = NULL;
	f->prox = NULL;
	return f;
}

void printa(Lista* l) {
	Lista* temp = l;
	if (temp->info == NULL)
		printf("LISTA VAZIA");
	else {
		do {
			printf("%d, ", temp->info);
			temp = temp->prox;
		} while (temp->prox != NULL);
	}
}

void armazena(Lista* l, int num) {
	Lista* n = (Lista*)malloc(sizeof(Lista));
	if (n == NULL)
		exit(3);

	n->info = num; 
	n->prox = NULL;

	if (l->info == NULL)
		l = n;
	else if (l->prox == NULL)
		l->prox = n;
	else {
		Lista* temp = l;
		while (temp->prox != NULL) {
			temp = temp->prox;
			temp->prox = n;
		}
	}
	printa(l);
}

//void retira(void) {
//	Lista* t;
//	int v;
//	if ((glob_fila->ini == NULL) && (glob_fila == NULL)) {
//		printf("Fila vazia.\n");
//		exit(2);
//	} /* aborta programa */
//	t = glob_fila->ini;
//	v = t->info;
//	glob_fila->ini = t->prox;
//	if (glob_fila->ini == NULL) /* verifica se fila ficou vazia */
//		glob_fila->fim = NULL;
//	free(t);
//}

int main(void) {
	FILE* f = fopen(arq_fila, "r");
	if (f != NULL)
		exit(1);

	Lista* fila = fila_cria();

	while (true) {
		char el;
		fscanf(f, "%c", &el);
		if (el == ' ')
			continue;
		else if (el == '\n')
			break;
		else if (el == 'a') {
			// adiciona prox num
			int num;
			fscanf(f, "%d", &num);
			armazena(fila, num);
		}
		else if (el == 'r') {
			// remover 1º elemento
			//retira();
		}
	}

	fclose(f);
	return 0;
}