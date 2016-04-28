#include <mem.h>

void
create_segment (unsigned int index, unsigned int base, unsigned int limit, unsigned short flags)
{
  gdt[index].limit0_15 = limit & 0xFFFF;
  gdt[index].base0_15 = base & 0xFFFF;
  gdt[index].base16_23 = (base >> 16) & 0xFF;
  gdt[index].flags = flags | ((limit >> 8) & 0x0F00);
  gdt[index].base24_31 = (base >> 24) & 0xFF;
}
