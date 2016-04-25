#include <kernel/paging.h>

PD page_directory[];

__attribute__((__aligned__(PGSIZE)))
PD page_directory[PDSIZE] = {
	[0] = (0) | PDE_PRESENT | PDE_RW | PDE_SIZE,
	[512] = (0) | PDE_PRESENT | PDE_RW | PDE_SIZE
};
