#include <string.h>

#include <kernel/vga.h>
#include <kernel/tty.h>


// start vga.h definitions
static inline char make_color(vga_color fg, vga_color bg)
{
	return fg | bg << 4;
};

static inline short make_vgaentry(char c, char color)
{
	short c16 = c;
	short color16 = color;
	return c16 | color16 << 8;
}

static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;

static short* const VGA_MEMORY = (short*) 0xB8000;
// end vga.h definitions

int terminal_row;
int terminal_column;
char terminal_color;
short* terminal_buffer;

void terminal_setcolor(char color)
{
	terminal_color = color;
}

void terminal_initialize(void)
{
	terminal_row = 1;
	terminal_column = 0;
	terminal_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
}

void terminal_putentryat(char c, char color, int x, int y)
{
	const int index = y * VGA_WIDTH + x;
	terminal_buffer[index] = make_vgaentry(c, color);
}

void terminal_putchar(char c)
{
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH)
	{
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
		{
			terminal_row = 0;
		}
	}
}

void terminal_write(const char* data, char size)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == '\n')
		{
			++terminal_row;
			terminal_column = 0;
		}
		else
		{
			terminal_putchar(data[i]);
		}
	}
}

void terminal_writestring(const char* data)
{
	terminal_write(data, strlen(data));
}
