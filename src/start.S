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

    ldr x2, #0 // Disable mmu(for now)
    msr sctlr_el1, x2

    ldr x2, =(1 << 31) // Essentially makes it so that el1 runs in 64bit and that el1 instructions don't trap to el2
    msr hcr_el2, x2

#ifdef QEMU // qemu boots at el2, unlike rpi3 at el3, so less stuff to configure
    ldr x2, =(5 | (7 << 6)) //Makes it so that eret goes to el1, all interrupts are masked and we use the el1 stack pointer
    msr spsr_el2, x2

    adr x2, memzero
    msr elr_el2, x2 //sets memzero as the return address for eret
#else // rpi3 boots into EL3.
    ldr x2, =((1) | (1 << 10) | (3 << 4)) // Similar to configuring el2, just scr_el3 vs hcr_el2
    msr scr_el3, x2

    ldr x2, =(5 | (7 << 6)) //same as above, but from el3 to el1
    msr spsr_el3, x2

    adr x2, memzero
    msr elr_el3, x2 //same as above
#endif
    eret
memzero: //zeroes out memory from bss_begin to bss_end
    str xzr, [x0], #8
    cmp x0, x1
    b.le memzero
load_stack:
    mov sp, #4194304
    bl kernel_main
    b sleep // should not get here
