#include <multiboot.h>

#include <paging.h>
#include <vga.h>
#include <mem.h>

#include <string.h>

#if defined(__linux__)
#error "You are not using a cross-compiler!"
#endif

#if !defined(__i386__)
#error "This needs to be compiled with an ix86-elf compiler"
#endif

// Provided by linker.ld
extern char text[], etext[], data[], edata[], end[];

void main(multiboot_info_t* mbd, unsigned int magic)
{
	printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890\n");
	printf("Long Long : %d\n", sizeof(long long));
	printf("End of ELF address: %x\n", &end);
	printf("Multiboot info: %x Lower Memory: %dKB Upper Memory: %dKB\n",
		magic, mbd->mem_lower, mbd->mem_upper);

 	create_segment(0,0,0,0);
 	create_segment(1,0,0xFFFFF,0x4092);
	create_segment(2,0,0xFFFFF,0x409A);

	printf("%x, %x, %x, %x, %x\n", gdt[1].limit0_15, gdt[1].base0_15, gdt[1].base16_23, gdt[1].flags, gdt[1].base24_31);
	printf("%x, %x, %x, %x, %x\n", gdt[2].limit0_15, gdt[2].base0_15, gdt[2].base16_23, gdt[2].flags, gdt[2].base24_31);
}
