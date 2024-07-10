#include "uart.h"
#include "util.h"
#include <stdint.h>

void kernel_main() {
  uint32_t i = 0xdeadbeef;

  uart_init();

  uart_send('h');
  uart_send('i');
  uart_send('\n');

  while (1) {
    i++;
    sleep(100000000);
    uart_send('b');
    uart_send('\n');
  }
}
