#include "irq.h"
#include "debug.h"
#include "util.h"

void unimpl_irq_handle() {
    puts("Unimplemented irq, exiting...\n");

    while(1) {
        wait();
    }
}