/*
int fat (int n) 
  if (n==0) return 1;
  else return n*fat(n-1);
*/

.text
.globl fat
fat:
    pushq %rbp            # Guarda a base da função anterior [cite: 79, 243]
    movq  %rsp, %rbp      # Define a nova base para esta chamada [cite: 91, 245]
    subq  $16, %rsp       # Alinha a pilha e reserva espaço (múltiplo de 16) [cite: 169, 181]

    cmp $0, %edi     
    jne recursao

    movl $1, %eax
    jmp final

recursao:
    movl %edi, -4(%rbp)

    subl $1, %edi
    call fat

    imull -4(%rbp), %eax

final:
    leave 
    ret
    