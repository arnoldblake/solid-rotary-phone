#ifndef __PAGING_H
#define __PAGING_H

#include <types.h>

#define PE_P        0x001   // Present if set otherwise not present in memory
#define PE_W        0x002   // Write if set otherwise read only
#define PE_U        0x004   // User if set otherwise supervisor only
#define PE_WT		    0x008   // Write-through if set otherwise write-back
#define PE_C		    0x010   // Cache disable if set otherwise cache enabled
#define PE_A        0x020   // Accessed if set page has been read or written to
#define PE_D        0x040   // Page table entry has been written
#define PE_S        0x080   // Page size if set 4MB otherwise 4KB
#define PE_MBZ      0x100   // Must be zero

#define PDSIZE  1024
#define PTSIZE  1024
#define PGSIZE  4096  // 4KB pages

#define PGROUNDUP(x) ((x + PGSIZE - 1) & ~(PGSIZE - 1))
#define PGROUNDDOWN(x) ((x) & ~(PGSIZE -1))

__attribute__((__aligned__(PGSIZE)))
PD page_directory[PDSIZE];

#endif
