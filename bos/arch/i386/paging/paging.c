#include <kernel/paging.h>

__attribute__((__aligned__(PGSIZE)))
PD page_directory[PDSIZE] =
{
	[0] = 	(0) | PE_P | PE_W | PE_S,
	[512] = (0) | PE_P | PE_W | PE_S
};
