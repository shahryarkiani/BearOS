#include "util.h"
#include "BCM2837.h"
#include "gpio.h"
#include "uart.h"

void uart_init() {
  // We set pins 14/15 to be used for uart i/o
  gpio_set_function(14, GPIO_FUNCTION_5);
  gpio_set_function(15, GPIO_FUNCTION_5);

  gpio_set_pull(14, GPIO_PULL_OFF);
  gpio_set_pull(15, GPIO_PULL_OFF);

  // Enable the mini uart
  // Might want to change this later to not overwrite existing settings
  write32(BCM2837_AUX_ENABLES, 0);
  write32(BCM2837_AUX_MU_CNTL_REG, 0);

  write32(BCM2837_AUX_MU_IER_REG, 0); // Don't want interrupts yet
  write32(BCM2837_AUX_MU_LCR_REG, 3);
  write32(BCM2837_AUX_MU_MCR_REG, 0);
  write32(BCM2837_AUX_MU_IIR_REG, 6); // Clear's the FIFO for receive + transmit
  write32(BCM2837_AUX_MU_BAUD_REG, 270);

  write32(BCM2837_AUX_MU_CNTL_REG, 3);
}

void uart_send(char ch) {

  while (!(read32(BCM2837_AUX_MU_LSR_REG) & 0x20)) {
  } // We spin until we can write

  write32(BCM2837_AUX_MU_IO_REG, ch);
}

char uart_recv() {

  while (!(read32(BCM2837_AUX_MU_LSR_REG) & 1)) {
  } // We spin until data is ready to be read

  return read32(BCM2837_AUX_MU_IO_REG) & 0xFF;
}
