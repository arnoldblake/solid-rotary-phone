#ifndef _STRING_H
#define _STRING_H 1

#include <stddef.h>
#include <stdint.h>

size_t strlen(const uint8_t*);
void reverse(uint8_t string[]);
void itoa(int32_t n, uint8_t s[]);

#endif
