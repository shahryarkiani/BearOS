#include "irq.h"
#include "debug.h"
#include "util.h"
#include "timer.h"
#include "BCM2837.h"

void unimpl_irq_handle() {
    puts("Unimplemented irq, exiting...\n");
    while(1) {
        sleep(0);
    }
}

void irq_handle() {
    puts("Handling timer irq\n");
    timer_refresh();
    irq_enable();
    puts("Done handling\n");
}

void irq_controller_enable() {
    write32(BCM2837_CORE0_TIMER_INTERRUPT_CONTROL_REG, 0b10);
}