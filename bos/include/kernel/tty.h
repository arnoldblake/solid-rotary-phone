#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_write(const char* data, char size);
void terminal_writestring(const char* string);

#endif
