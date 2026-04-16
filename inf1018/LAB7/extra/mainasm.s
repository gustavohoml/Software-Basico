/*
#include <stdio.h>
#include "dados.h"
int main() {
  int i;
  St *p = dados;
  int max = 0;
  for (i = 0; i <3; i++) {
     if (p->cc && p->ci > max)
       max = p->ci;
     p++;
  }
  printf("%d\n",max);
  return 0;}
*/

.section .text 
.extern dados

.data 
Sf:  .string "%c"    /* primeira string de formato para printf */
Sf2: .string "\n"    /* segunda string de formato para printf */

.globl main
main:
    movq $dados, %r12   /* r12 = &dados */
    movl $0, %eax       /* i = 0 */
    movl $0, %ebx       /* max = 0 */
L1:
    cmpl $3, %eax
    je L2

    cmpl $1, (%r12)
    jne apos_max
    
    cmpl 4(%r12), %ebx 
    jle apos_max

    movl 4(%r12), %ebx

apos_max:
    addq  $8, %r12
    jmp L1

L2:
    movq  $Sf, %rdi
    movl  %ebx, %esi
    movl  $0, %ebx
    call printf

    movq  $Sf2, %rdi    
    movl  $0, %eax
    call  printf       

    leave 
    ret
