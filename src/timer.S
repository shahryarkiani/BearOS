.globl timer_init
timer_init:
    mov x0, #1
    msr CNTP_CTL_EL0, x0
    ret

.globl timer_refresh
timer_refresh:
    ldr x0, =(1 << 25)
    msr CNTP_TVAL_EL0, x0
    ret 