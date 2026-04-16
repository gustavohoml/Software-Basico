/*
void foo (int a[], int n) 
  int i;
  int s = 0;
  for (i=0; i<n; i++) 
    s += a[i];
    if (a[i] == 0) 
      a[i] = s;
      s = 0;
*/

.text
.globl foo
foo:
    /* PROLOGO */
    pushq %rbp            # Guarda base anterior [cite: 243, 244]
    movq  %rsp, %rbp      # Define nova base [cite: 245]
    subq  $16, %rsp       # Aloca espaço no RA [cite: 246, 247]
    movq  %rbx, -8(%rbp)  # Salva o valor original de %rbx [cite: 248, 249]
    movq  %r12, -16(%rbp) # Salva o valor original de %r12 [cite: 250]

    movl $0, %ebx        /* int i = 0 */
    movl $0, %ecx        /* int s = 0 */

loop:
    cmpl %ebx, %esi
    je fora

    addl (%rdi), %ecx
    cmpl $0, (%rdi)
    jne else

    movl %ecx, (%rdi)
    movl $0, %ecx

else:
    addl $1, %ebx
    addq $4, %rdi
    jmp loop
    
fora:
    leave
    ret
