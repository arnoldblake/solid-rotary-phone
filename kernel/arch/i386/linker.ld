ENTRY(_start)

SECTIONS
{
	. = 1M;

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
		*(.bss *._stack)
	}

	PROVIDE(end = .);

}
