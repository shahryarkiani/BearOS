#include "debug.h"
#include "uart.h"
#include "util.h"
#include "irq.h"
#include "timer.h"
#include <stdint.h>

void kernel_main() {
  uint32_t i = 0xdeadbeef;

  uart_init();
  puts("mini uart initialized!\n");
  irq_vectors_init();
  puts("irq vector table initialized\n");
  irq_controller_enable();
  irq_enable();
  timer_init();
  timer_refresh();

  while (1) {
    i++;
    sleep(1000000000);
    puts("I'm still alive!!!\n");
  }
}
