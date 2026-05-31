.globl foo1
foo1:
    pushq %rbp
    movq %rsp, %rbp
    subq $4, %rsp
    movss %xmm1, -4(%rbp)
    call sin
    addss -4(%rbp), %xmm0
    leave
    ret
    