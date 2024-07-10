#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdint.h>

// Values from BCM2837 manual
// These 3 bit values are used to set the function of a GPIO pin
typedef enum {
  GPIO_INPUT = 0b00,
  GPIO_OUTPUT = 0b001,
  GPIO_FUNCTION_0 = 0b100,
  GPIO_FUNCTION_1 = 0b101,
  GPIO_FUNCTION_2 = 0b110,
  GPIO_FUNCTION_3 = 0b111,
  GPIO_FUNCTION_4 = 0b011,
  GPIO_FUNCTION_5 = 0b010
} gpio_function_t;

typedef enum {
  GPIO_PULL_OFF = 0b00,
  GPIO_PULL_DOWN = 0b01,
  GPIO_PULL_UP = 0b10
} gpio_pull_t;

void gpio_set_function(const uint32_t pin, const gpio_function_t func);
void gpio_set_pull(const uint32_t pin, gpio_pull_t pull);

#endif // _GPIO_H_
