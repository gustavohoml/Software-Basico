  .data
  s1: .string "ls -ls"

  .text
  .globl main
  main:
  /* prologo */
    pushq %rbp
    movq  %rsp, %rbp

  /* coloque seu codigo aqui */
    movq    $s1, %rdi    /* primeiro parametro (ponteiro)*/
    call  system       /* chama a funcao da biblioteca */


  /* finalizacao */
    leave
    ret
