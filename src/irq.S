.balign 2048
.globl vectors
vectors:
    // Current EL, SP0
    .balign 128 // Synchronous
    b not_impl
    .balign 128 // IRQ/vIRQ
    b not_impl
    .balign 128 // FIQ/vFIQ
    b not_impl
    .balign 128 // SError/vSError
    b not_impl
    
    // Current EL, SPn
    .balign 128 // Synchronous
    b not_impl
    .balign 128 // IRQ/vIRQ
    b not_impl
    .balign 128 // FIQ/vFIQ
    b not_impl
    .balign 128 // SError/vSError
    b not_impl

    // from 64 bit lower EL
    .balign 128 // Synchronous
    b not_impl
    .balign 128 // IRQ/vIRQ
    b not_impl
    .balign 128 // FIQ/vFIQ
    b not_impl
    .balign 128 // SError/vSError
    b not_impl

    // from 32 bit lower EL
    .balign 128 // Synchronous
    b not_impl
    .balign 128 // IRQ/vIRQ
    b not_impl
    .balign 128 // FIQ/vFIQ
    b not_impl
    .balign 128 // SError/vSError
    b not_impl

.global irq_vectors_init
irq_vectors_init:
    adr x0, vectors
    msr vbar_el1, x0
    ret

not_impl:
    b unimpl_irq_handle