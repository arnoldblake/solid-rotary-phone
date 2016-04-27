#ifndef __X86_H
#define __X86_H

static inline unsigned char
inb (unsigned short port)
{
  unsigned char data;

  asm volatile("in %1,%0" : "=a" (data) : "d" (port));
  return data;
}

static inline void
outb (unsigned short port, unsigned char data)
{
  asm volatile("out %0,%1" : : "a" (data), "d" (port));
}

static inline void
cli (void)
{
  asm volatile("cli");
}

static inline void
sti (void)
{
  asm volatile("sti");
}

#endif
