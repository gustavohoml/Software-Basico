#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ord = 1;  // 1 para ordenacao normal, 2 para ordenacao Buble e 3 para Selection Bubble 

void printa(int* v) {
	printf("[");
	for (int i = 0; i < 10; i++) {
		printf("%d ", v[i]);
	}
	printf("] ");
	switch (ord) {
		case 1: printf("<-- Vetor Embaralhado\n"); break;
		case 2: printf("<-- Ordenacao Bubble\n"); break;
		case 3: printf("<-- Ordenacao Selection\n"); break;
		default: break;
	}
}

void selectionSort(int* v) {
	for (int i = 0; i < 10; i++) {
        int pos = i; 
        for (int j = i; j < 9; j++) {
			if (v[pos] > v[j + 1]) 
				pos = j + 1;
        }
		int temp = v[i];
		v[i] = v[pos];
		v[pos] = temp;
    }
	ord++;
	printa(v);
}

void bubbleSort(int* v) {
    for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 9 - j; i++) {
	        if (v[i] > v[i + 1]) {
	            int temp = v[i];
	            v[i] = v[i + 1];
	            v[i + 1] = temp;
	        }
	    }
	}
	ord++;
	printa(v);
}

int main(void) {
	srand(time(NULL));
	int v[10];
	for (int i = 0; i < 10; i++) 
		v[i] = (rand() % 100) + 1;

	printa(v);
	bubbleSort(v);
	selectionSort(v);

	return 0;
}