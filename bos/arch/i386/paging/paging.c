#include <paging.h>

PD page_directory[PDSIZE] =
{
	[0] = 	(0) | PE_P | PE_W | PE_S,
	[512] = (0) | PE_P | PE_W | PE_S
};
