#ifndef _UTIL_H
#define _UTIL_H

#include <stdint.h>

extern void sleep(uint64_t cycles);
extern void write32(uint64_t addr, uint32_t val);
extern uint32_t read32(uint64_t addr);
extern void wait();

#endif // _UTIL_H
