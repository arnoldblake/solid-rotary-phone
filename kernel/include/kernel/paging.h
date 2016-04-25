#ifndef __PAGING_H
#define __PAGING_H

#define PDE_PRESENT     0x001   // Present
#define PDE_RW          0x002   // Writeable
#define PDE_USER        0x004   // User / Supervisor
#define PDE_WT		      0x008   // Write-through / Write-back
#define PDE_D			      0x010   // Cache Disable
#define PDE_A			      0x020   // Accessed
#define PDE_SIZE        0x080   // Page Size

#define PDSIZE    		  1024
#define PTSIZE    		  1024
#define PGSIZE          4096

typedef unsigned int PD;

#endif
