#ifndef _IRQ_H
#define _IRQ_H

extern void irq_vectors_init();
void irq_handle();
void unimpl_irq_handle();

#endif // _IRQ_H