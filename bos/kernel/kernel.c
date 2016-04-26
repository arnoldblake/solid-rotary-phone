#include <stddef.h>
#include <stdint.h>

#include <string.h>
#include <kernel/tty.h>
#include <kernel/paging.h>

#if defined(__linux__)
#error "You are not using a cross-compiler!"
#endif

#if !defined(__i386__)
#error "This needs to be compiled with an ix86-elf compiler"
#endif

// Provided by linker.ld
extern char etext[];
extern char data[];
extern char edata[];
extern char end[];

extern unsigned int stack_bottom;
extern unsigned int stack_top;


void main(PD page_directory)
{
	terminal_initialize();
	terminal_writestring("Hello world!\n");

	char buffer[12];
	terminal_writestring("End of .text address: ");
	itoa((int) &etext, buffer, 16);
	terminal_writestring(buffer);
	terminal_writestring("\n");
	terminal_writestring("Begin of data address: ");
	itoa((int) &data, buffer, 16);
	terminal_writestring(buffer);
	terminal_writestring("\n");
	terminal_writestring("End of data address: ");
	itoa((int) &edata, buffer, 16);
	terminal_writestring(buffer);
	terminal_writestring("\n");
	terminal_writestring("End of ELF address: ");
	itoa((int) &end, buffer, 16);
	terminal_writestring(buffer);
	terminal_writestring("\n");
	terminal_writestring("Begin of stack address: ");
	itoa((int) &stack_bottom, buffer, 16);
	terminal_writestring(buffer);
	terminal_writestring("\n");
}
