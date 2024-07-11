#include "debug.h"
#include "uart.h"
#include "util.h"
#include <stdint.h>

void kernel_main() {
  uint32_t i = 0xdeadbeef;

  uart_init();
  puts("Hello, World!\n");

  while (1) {
    i++;
    sleep(1000000000);
    puts("I'm still alive!!!\n");
  }
}
