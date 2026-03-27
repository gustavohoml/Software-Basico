.data
nums:  .int  10, -21, -30, 45
Sf:  .string "%d\n"    # string de formato para printf

.text
.globl  main
main:

  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12, -16(%rbp)






  movl  $0, %ebx      # i = 0 (ebx é callee-saved, printf não mexe aqui)
  movq  $nums, %r12   # p = nums (r12 é callee-saved)
  movl  $0, %r10d     # r10d = sum (Usaremos r10d para a soma, mas cuidado com o printf!)

L1:
  cmpl  $4, %ebx      # i != 4?
  je    L2            # Se i == 4, sai do loop
  
  addl  (%r12), %r10d # sum += *p (Soma o valor apontado por r12 em r10d)

  # Removi o printf daqui de dentro, pois o C pede para imprimir SÓ NO FINAL.

  addl  $1, %ebx      # i++
  addq  $4, %r12      # p++ (4 bytes pois é um int)
  jmp   L1

L2:  
  # Agora sim, imprimimos a soma acumulada
  movq    $Sf, %rdi   # 1º param: formato
  movl    %r10d, %esi # 2º param: o valor da soma
  movl    $0, %eax    # printf precisa de rax=0 para funções sem ponto flutuante
  call    printf

  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq  -8(%rbp), %rbx
  movq  -16(%rbp), %r12
  leave
  ret 