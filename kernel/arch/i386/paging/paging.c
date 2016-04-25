#include <kernel/paging.h>

__attribute__((__aligned__(PGSIZE)))
PDT pdt[NPDENTRIES] = {
	[0] = (0) | PDE_PRESENT | PDE_RW | PDE_SIZE,
	[512] = (0) | PDE_PRESENT | PDE_RW | PDE_SIZE
};
