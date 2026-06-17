#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h> // Biblioteca necessária para o mprotect
#include <unistd.h>   // Biblioteca necessária para o sysconf

typedef int (*funcp) (int x);

int foo(int n);

int add (int x) {
  return x+1;
}

int main(void) {
    //printf("2 -> %d \n", foo(2));
    static unsigned char codigo[] = {0xe9, 0x00, 0x00, 0x00, 0x00, 0xc3};
    // ^ e8 -> e9

    // --- INÍCIO DA MÁGICA DO LINUX ---
    // Descobrimos o tamanho da "página" de memória do computador (geralmente 4096 bytes)
    long pagesize = sysconf(_SC_PAGESIZE);
    // Encontramos o endereço exato onde a página do nosso array começa
    void *page_start = (void *)((long)codigo & ~(pagesize - 1));
    // Damos a ordem ao Linux: Torne essa página de memória Executável (PROT_EXEC)!
    mprotect(page_start, pagesize, PROT_READ | PROT_WRITE | PROT_EXEC);
    // --- FIM DA MÁGICA ---
    
    

    long end_destino = (long)add;
    long end_prox_instrucao = (long)(&codigo[5]);
    int32_t offset = (int32_t)(end_destino - end_prox_instrucao);
    *((int32_t*)(&codigo[1])) = offset;

    funcp f = (funcp)codigo;
    int i = (*f)(10);
    printf("i: %d \n", i);

    return 0;
}