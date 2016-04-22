ENTRY(_start)

SECTIONS
{  	
	. = 1M;

	/* Code */
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}
	
	/* Initialized Read Only Data */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}
	
	/* Initialized Data */
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}
	
	/* Un-initialized Data */
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
		*(._stack)
	}
}
