#include <stdio.h>
#include <stdlib.h>
// exit 0 = Sucesso
// exit 1 = Erro ao alocar memoria 

typedef struct treebin TreeBin;

struct treebin {
	int info;
	TreeBin* dir;
	TreeBin* esq;
};

TreeBin* cria_arv_bin(void) {
	TreeBin* arv = (TreeBin*)malloc(sizeof(TreeBin));
	if (arv == NULL) 
		exit(1);
	arv->dir = NULL;
	arv->esq = NULL;
	return arv;
}

int main(void) {
	TreeBin* binarv = cria_arv_bin(); 

	free(binarv);
	return 0;
}