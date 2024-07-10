.section ".text.boot"
.globl _start
_start: //Each core starts running the same code
    //read from Multiprocess Affinity Register
    mrs x1, mpidr_el1
    //The lower 8 bits store the core number
    and x1, x1, #0xFF
    cbz x1, main // If this is core zero we branch to kernel main
    b sleep

sleep: // The other cores come here
    wfi // (Wait For Interrupt) Puts the core into standby
    b sleep

main:
    adr x0, bss_begin
    adr x1, bss_end
memzero: //zeroes out memory from bss_begin to bss_end
    str xzr, [x0], #8
    cmp x0, x1
    b.le memzero
load_stack:
    mov sp, #4194304
    bl kernel_main
    b sleep // should not get here