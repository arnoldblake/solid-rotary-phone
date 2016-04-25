#ifndef _IDT_H
#define _IDT_H

typedef unsigned long long IDT;

typedef struct {
  unsigned short size;
  unsigned int* address;
} __attribute__((packed)) IDT_DESCRIPTOR;

#endif
