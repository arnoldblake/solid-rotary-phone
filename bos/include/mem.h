#ifndef __MEM_H
#define __MEM_H

#define GDT_SIZE 10

#define DF_S      0x0010
#define DF_DPL_0  0x0000
#define DF_DPL_1  0x0020
#define DF_DPL_2  0x0040
#define DF_DPL_3  0x0060

struct segment_descriptor {
  unsigned short  limit0_15;
  unsigned short  base0_15;
  unsigned char   base16_23;
  unsigned short  flags;
  unsigned char   base24_31;
} gdt[GDT_SIZE];

void
create_segment (unsigned int index, unsigned int base, unsigned int limit, unsigned short flags);

#endif
