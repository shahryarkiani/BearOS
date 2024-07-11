#include "debug.h"
#include "uart.h"


void puts(const char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        uart_send(str[i]);
    }
}