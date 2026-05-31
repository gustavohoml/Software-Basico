.globl foo3
foo3:
    pushq %rbp
    movq %rsp, %rbp
    
    # Salvando os callee-saved que vamos usar!
    pushq %rbx      # Vamos usar para o ponteiro 'a'
    pushq %r12      # Vamos usar para 'i'
    pushq %r13      # Vamos usar para 'n'
    
    # Alinhando a pilha e abrindo espaço para o 'r'
    subq $8, %rsp   

    # --- Inicializações ---
    movq %rdi, %rbx      # %rbx = a
    movl %esi, %r13d     # %r13d = n
    movl $0, %r12d       # %r12d = i (i = 0)
    
    # r = 0.0 na pilha (vou colocar no -32(%rbp), pois já usamos 24 bytes com os pushes)
    pxor %xmm0, %xmm0
    movsd %xmm0, -32(%rbp) 

while:
    # --- Condição do laço ---
    cmpl %r13d, %r12d    # Compara n com i (ATENÇÃO: a ordem é inversa no cmpl)
    jge fora             # Se i >= n, sai do laço

    # --- Corpo do laço ---
    # 1. Pegue o valor *a e coloque no %xmm0
    movsd (%rbx), %xmm0

    # 2. call sin
    call sin
    
    # 3. Some o retorno do sin (%xmm0) com o 'r' atual da pilha (-32(%rbp))
    addsd -32(%rbp), %xmm0

    # 4. Salve o novo valor de 'r' de volta na pilha
    movsd %xmm0, -32(%rbp)
    
    # 5. a++ (Lembrete: some 8 bytes no ponteiro %rbx!)
    addq $8, %rbx
    
    # 6. i++ (Some 1 no %r12d)
    addl $1, %r12d

    jmp while

fora:
    # 7. Coloque a resposta final 'r' no %xmm0 para o retorno
    movsd -32(%rbp), %xmm0
    
    # --- Epílogo ---
    addq $8, %rsp        # Fecha o espaço que abrimos
    popq %r13            # Restaura os callee-saved (na ordem inversa do push!)
    popq %r12
    popq %rbx
    leave
    ret





















/*
  int i;
  double r = 0.0;
  for (i=0; i<n; i++) {
    r += sin(*a);
    a++;
  }
  return r;
*/

/*
globl foo3
foo3:
  pushq %rbp
  movq %rsp, %rbp
  subq $16, %rsp
  movsd %xmm0, -8(%rbp)         
  movsd $0, %xmm1                 
  movl %edi, %ebx               
  movl $0, %r12d                 

while:
  cmpl %r12d, %ebx
  jge fora

  movsd -8(%rbp), %xmm0
  call sin
  addsd %xmm0, %xmm1

  addsd

fora:
*/