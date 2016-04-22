#include <stddef.h>
#include <stdint.h>

#include <string.h>

#include <kernel/tty.h>
#include <kernel/mmu.h>
#include <kernel/types.h>

#if defined(__linux__)
#error "You are not using a cross-compiler!"
#endif

#if !defined(__i386__)
#error "This needs to be compiled with an ix86-elf compiler"
#endif

pd_t page_directory[];

void kmain()
{
	terminal_initialize();

	char* string = "Hello world!\n";
	terminal_writestring((uint8_t*) string);
}

__attribute__((__aligned__(PGSIZE)))
pd_t page_directory[NPDENTRIES] = {
	[0] = (0) | PDE_PRESENT | PDE_RW | PDE_SIZE,
	[512] = (0) | PDE_PRESENT | PDE_RW | PDE_SIZE
};
