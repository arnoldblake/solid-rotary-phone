ENTRY(_start)

SECTIONS
{
	. = 1M;
	PROVIDE(text = .);

	.text :
	{
		*(.multiboot .text)
	}
	PROVIDE(etext = .);

	.rodata :
	{
		*(.rodata)
	}

	. = ALIGN(0x1000);
	PROVIDE(data = .);

	.data  :
	{
		*(.data)
	}

	PROVIDE(edata = .);

	.bss :
	{
		*(.bss)
	}

	.stack :
	{
	 *(.stack)
	}

	PROVIDE(end = .);
}
