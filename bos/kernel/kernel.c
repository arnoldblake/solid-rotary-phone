#include <multiboot.h>

#include <kernel/paging.h>
#include <kernel/vga.h>

#include <string.h>

#if defined(__linux__)
#error "You are not using a cross-compiler!"
#endif

#if !defined(__i386__)
#error "This needs to be compiled with an ix86-elf compiler"
#endif

// Provided by linker.ld
extern char text[], etext[], data[], edata[], end[];
// Stack
extern unsigned int stack_bottom, stack_top;

void main(multiboot_info_t* mbd, unsigned int magic)
{
	printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890\n");
	printf("End of ELF address: %x\n", &end);
	printf("Multiboot info: %x Lower Memory: %dKB Upper Memory: %dKB",
		magic, mbd->mem_lower, mbd->mem_upper);
}
