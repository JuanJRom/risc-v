.globl trap_entry
.align 4
trap_entry:
        # make room to save registers.
        addi sp, sp, -256
        # save the registers.
        sd ra, 0(sp)
        sd sp, 8(sp)
        sd gp, 16(sp)
        sd tp, 24(sp)
        sd t0, 32(sp)
        sd t1, 40(sp)
        sd t2, 48(sp)
        sd s0, 56(sp)
        sd s1, 64(sp)
        sd a0, 72(sp)
        sd a1, 80(sp)
        sd a2, 88(sp)
        sd a3, 96(sp)
        sd a4, 104(sp)
        sd a5, 112(sp)
        sd a6, 120(sp)
        sd a7, 128(sp)
        sd s2, 136(sp)
        sd s3, 144(sp)
        sd s4, 152(sp)
        sd s5, 160(sp)
        sd s6, 168(sp)
        sd s7, 176(sp)
        sd s8, 184(sp)
        sd s9, 192(sp)
        sd s10, 200(sp)
        sd s11, 208(sp)
        sd t3, 216(sp)
        sd t4, 224(sp)
        sd t5, 232(sp)
        sd t6, 240(sp)

        call handle_trap
        # restore registers.
        ld ra, 0(sp)
        ld sp, 8(sp)
        ld gp, 16(sp)
        # not this, in case we moved CPUs: ld tp, 24(sp)
        ld t0, 32(sp)
        ld t1, 40(sp)
        ld t2, 48(sp)
        ld s0, 56(sp)
        ld s1, 64(sp)
        ld a0, 72(sp)
        ld a1, 80(sp)
        ld a2, 88(sp)
        ld a3, 96(sp)
        ld a4, 104(sp)
        ld a5, 112(sp)
        ld a6, 120(sp)
        ld a7, 128(sp)
        ld s2, 136(sp)
        ld s3, 144(sp)
        ld s4, 152(sp)
        ld s5, 160(sp)
        ld s6, 168(sp)
        ld s7, 176(sp)
        ld s8, 184(sp)
        ld s9, 192(sp)
        ld s10, 200(sp)
        ld s11, 208(sp)
        ld t3, 216(sp)
        ld t4, 224(sp)
        ld t5, 232(sp)
        ld t6, 240(sp)
        
        addi sp, sp, 256
        mret

.globl store_context
store_context:
        # make room to save registers.
        #addi sp, sp, -256
         #add a0, a0, 1  # a0++
         sd ra, 0(a0)
         sd sp, 8(a0)
         sd gp, 16(a0)
         sd tp, 24(a0)
         sd t0, 32(a0)
         sd t1, 40(a0)
         sd t2, 48(a0)
         sd s0, 56(a0)
         sd s1, 64(a0)
         sd a0, 72(a0)
         sd a1, 80(a0)
         sd a2, 88(a0)
         sd a3, 96(a0)
         sd a4, 104(a0)
         sd a5, 112(a0)
         sd a6, 120(a0)
         sd a7, 128(a0)
         sd s2, 136(a0)
         sd s3, 144(a0)
         sd s4, 152(a0)
         sd s5, 160(a0)
         sd s6, 168(a0)
         sd s7, 176(a0)
         sd s8, 184(a0)
         sd s9, 192(a0)
         sd s10, 200(a0)
         sd s11, 208(a0)
         sd t3, 216(a0)
         sd t4, 224(a0)
         sd t5, 232(a0)
         sd t6, 240(a0)

        #addi sp, sp, 256
         ret
  
.globl load_context
#.align 4
load_context:
        # restore registers.
        ld ra, 0(a0)
        ld sp, 8(a0)
        ld gp, 16(a0)
        # not this, in case we moved CPUs: ld tp, 24(a0)
        ld t0, 32(a0)
        ld t1, 40(a0)
        ld t2, 48(a0)
        ld s0, 56(a0)
        ld s1, 64(a0)
        ld a0, 72(a0)
        ld a1, 80(a0)
        ld a2, 88(a0)
        ld a3, 96(a0)
        ld a4, 104(a0)
        ld a5, 112(a0)
        ld a6, 120(a0)
        ld a7, 128(a0)
        ld s2, 136(a0)
        ld s3, 144(a0)
        ld s4, 152(a0)
        ld s5, 160(a0)
        ld s6, 168(a0)
        ld s7, 176(a0)
        ld s8, 184(a0)
        ld s9, 192(a0)
        ld s10, 200(a0)
        ld s11, 208(a0)
        ld t3, 216(a0)
        ld t4, 224(a0)
        ld t5, 232(a0)
        ld t6, 240(a0)

        #addi sp, sp, 256
        ret

.globl test
test:  
        add a0, a0, 1  # a0++
        ret


#.globl timervec
#.align 4
#timervec:
        # start.c has set up the memory that mscratch points to:
        # scratch[0,8,16] : register save area.
        # scratch[32] : address of CLINT's MTIMECMP register.
        # scratch[40] : desired interval between interrupts.
        
#        csrrw a0, mscratch, a0
#        sd a1, 0(a0)
#        sd a2, 8(a0)
#        sd a3, 16(a0)

        # schedule the next timer interrupt
        # by adding interval to mtimecmp.
#        ld a1, 32(a0) # CLINT_MTIMECMP(hart)
#        ld a2, 40(a0) # interval
#        ld a3, 0(a1)
#        add a3, a3, a2
#        sd a3, 0(a1)

        # raise a supervisor software interrupt.
#	li a1, 2
#        csrw sip, a1

#        ld a3, 16(a0)
#        ld a2, 8(a0)
#        ld a1, 0(a0)
#        csrrw a0, mscratch, a0

#        mret
