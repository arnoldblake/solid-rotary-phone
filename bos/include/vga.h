#ifndef __VGA_H
#define __VGA_H

#define VGAPORT 0x3D4
#define VGAMEMORY 0xB8000

#define VGAWIDTH 80

#define VGACOLOR(x,y) (y << 8 | x << 4)

typedef enum
{
  COLOR_BLACK = 0,
  COLOR_BLUE = 1,
  COLOR_GREEN = 2,
  COLOR_CYAN = 3,
  COLOR_RED = 4,
  COLOR_MAGENTA = 5,
  COLOR_BROWN = 6,
  COLOR_LIGHT_GREY = 7,
  COLOR_DARK_GREY = 8,
  COLOR_LIGHT_BLUE = 9,
  COLOR_LIGHT_GREEN = 10,
  COLOR_LIGHT_CYAN = 11,
  COLOR_LIGHT_RED = 12,
  COLOR_LIGHT_MAGENTA = 13,
  COLOR_LIGHT_BROWN = 14,
  COLOR_WHITE = 15,
} VGA_COLOR;

void print(char* string);
void printf(char* string, ...);

#endif
