ENTRY(_start)

SECTIONS
{
	. = 1M;

	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot .text)
	}
	PROVIDE(etext = .);

	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	PROVIDE(data = .);

	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	PROVIDE(edata = .);

	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(.bss)
	}

	PROVIDE(end = .);

}
