#include "gpio.h"
#include "BCM2837.h"
#include "util.h"
#include <stdint.h>

#define FUNC_BITMASK 0b111

void gpio_set_function(const uint32_t pin, const gpio_function_t func) {
  const uint32_t offset = pin / 10;

  const uint32_t func_shift = (pin % 10) * 3;

  const uint64_t gpfsel_addr = BCM2837_GPFSEL0 + offset * 4;

  uint32_t setting = read32(gpfsel_addr);

  // Clear the current setting
  setting &= ~(FUNC_BITMASK << func_shift);
  // Put in the new function
  setting |= ~(func << func_shift);

  // Write back the setting
  write32(gpfsel_addr, setting);
}

void gpio_set_pull(const uint32_t pin, gpio_pull_t pull) {
  // We need to update the GPIO pull up/down clock registers
  // But that depends on which pin we're changing
  uint32_t clock_num = pin / 32;

  // If pin == 32, we don't want to get undefined behavior
  uint32_t setting = 1 << (pin & 31);

  // We specify what the new pull state will be
  write32(BCM2837_GPPUD, pull);
  // Manual says we need to wait at least 150 cycles
  sleep(150);

  const uint32_t gppudclock_addr = BCM2837_GPPUDCLK0 + clock_num * 4;

  write32(gppudclock_addr, setting);

  sleep(150);

  write32(gppudclock_addr, 0);
}
