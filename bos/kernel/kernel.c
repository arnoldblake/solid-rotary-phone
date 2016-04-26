#include <stddef.h>
#include <stdint.h>

#include <string.h>
#include <kernel/paging.h>
#include <vga.h>

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


void main(PD* page_directory)
{
	printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890\n");
	printf("End of .text address: %x\n", &etext);
	printf("Begin of data address: %x\n", &data);
	printf("End of data address: %x\n", &edata);
	printf("End of ELF address: %x\n", &end);
	printf("Top of stack address: %x\n", &stack_top);
	printf("Page Directory address: %x\n", page_directory);
}
