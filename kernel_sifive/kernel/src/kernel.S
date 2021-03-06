.section .text
.global osSchedulerLaunch
.type osSchedulerLaunch, @function
.extern currentPt
osSchedulerLaunch:
    lw t0, currentPt   # Load currentPt into T0
    lw t1, (t0)
    lw sp, (t0)        # t1 = &t0
    lw ra, (sp)
    addi sp, sp, -132   # make a stack frame
    ret

.data
.section .text
.global switch_to
.type switch_to, @function
.align 2
switch_to:

    call handle_trap
    mv tp, sp
    mv sp, fp
    #Push register
    sw ra, (sp)
    sw sp, 4(sp)
    sw gp, 8(sp)
    sw tp, 12(sp)
    sw t0, 16(sp)
    sw t1, 20(sp)
    sw t2, 24(sp)
    sw t3, 28(sp)
    sw s0, 32(sp)
    sw s1, 36(sp)
    sw a0, 40(sp)
    sw a1, 44(sp)
    sw a2, 48(sp)
    sw a3, 52(sp)
    sw a4, 56(sp)
    sw a5, 60(sp)
    sw a6, 64(sp)
    sw a7, 68(sp)
    sw s2, 72(sp)
    sw s3, 76(sp)
    sw s4, 80(sp)
    sw s5, 84(sp)
    sw s6, 88(sp)
    sw s7, 92(sp)
    sw s8, 96(sp)
    sw s9, 100(sp)
    sw s10,104(sp)
    sw s11,108(sp)
    sw t3, 112(sp)
    sw t4, 116(sp)
    sw t5, 120(sp)
    sw t6, 124(sp)
    csrr t0, mepc
    sw t0, 132(sp)

    #Switch context in assembly language, but it has an bug
    #lw t0, currentPt   # Load currentPt into T0
    #addi t0, t0, 4     # currentPt.nextPt
    #lw t1, (t0)        # stack_pt   registers
    #la t2, 0x8000087C  #this is for 4 threads
    #la t2, 0x80000874  #this is for 2 threads
    #sw t1, (t2)
    #lw sp, (t1)
    #addi sp, sp, -132  # make a stack frame
    #lw t0, 132(sp)     # load mepc
    #csrw mepc, t0

    #Switch context in c
    call osSchedulerRoundRobin
    lw t0, currentPt   # Load currentPt into T0
    lw sp, (t0)
    addi sp, sp, -132  # make a stack frame
    lw t0, 132(sp)     # load mepc
    csrw mepc, t0


    #Pop register
    lw ra, (sp)
    #lw sp, 4(sp)
    #lw gp, 8(sp)
    lw tp, 12(sp)
    lw t0, 16(sp)
    lw t1, 20(sp)
    lw t2, 24(sp)
    lw t3, 28(sp)
    lw s0, 32(sp)
    lw s1, 36(sp)
    lw a0, 40(sp)
    lw a1, 44(sp)
    lw a2, 48(sp)
    lw a3, 52(sp)
    lw a4, 56(sp)
    lw a5, 60(sp)
    lw a6, 64(sp)
    lw a7, 68(sp)
    lw s2, 72(sp)
    lw s3, 76(sp)
    lw s4, 80(sp)
    lw s5, 84(sp)
    lw s6, 88(sp)
    lw s7, 92(sp)
    lw s8, 96(sp)
    lw s9, 100(sp)
    lw s10,104(sp)
    lw s11,108(sp)
    lw t3, 112(sp)
    lw t4, 116(sp)
    lw t5, 120(sp)
    lw t6, 124(sp)

    mret
