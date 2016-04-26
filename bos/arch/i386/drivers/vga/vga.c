#include <vga.h>
#include <x86.h>
#include <string.h>

static unsigned short* buffer = (unsigned short*) VGAMEMORY;
static VGA_COLOR fg = COLOR_LIGHT_GREY;
static VGA_COLOR bg = COLOR_BLACK;
static int position;

static void vgaputc(char c)
{
  outb(VGAPORT, 14);
  position = inb(VGAPORT+1) << 8;
  outb(VGAPORT, 15);
  position |= inb(VGAPORT+1);

  if (c == '\n')
  {
    position += VGAWIDTH - position % VGAWIDTH;
  }
  else
  {
    buffer[position++] = c | VGACOLOR(bg, fg);
  }

  outb(VGAPORT, 14);
  outb(VGAPORT+1, position >> 8);
  outb(VGAPORT, 15);
  outb(VGAPORT+1, position);
  buffer[position] = ' ' | VGACOLOR(bg, fg);
}

void print(char* string)
{
  int i;
  for (i = 0; string[i] != 0 ; i++)
  {
    vgaputc(string[i]);
  }
}

void printf(char* string, ...)
{
  int i, c;
  unsigned int* argp;
  char buffer[11];

  argp = (unsigned int*) (&string +1);
  for (i = 0; (c = string[i]) != 0; i++)
  {
    if (c != '%')
    {
      vgaputc(string[i]);
      continue;
    }

    c = string[++i];
    switch (c)
    {
      case 'x':
      itoa(*argp++, buffer, 16);
      print(buffer);
      break;
    }
  }
}
