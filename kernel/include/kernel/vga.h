#ifndef _KERNEL_VGA_H
#define _KERNEL_VGA_H

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
} vga_color;

static inline char make_color(vga_color fg, vga_color bg);
static inline short make_vgaentry(char c, char color);

static const int VGA_WIDTH;
static const int VGA_HEIGHT;

static short* const VGA_MEMORY;

#endif
