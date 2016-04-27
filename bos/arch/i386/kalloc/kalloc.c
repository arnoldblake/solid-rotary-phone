#include <kernel/paging.h>

struct run
{
  struct run *next;
};

struct
{
  struct run *freelist;
} kmem;

void kfree (char *v)
{
  struct run *r;

  r = (struct run*) v;
  r->next = kmem.freelist;
  kmem.freelist = r;
}

char* kalloc (void)
{
  struct run* r;

  r = kmem.freelist;
  if(r)
  {
    kmem.freelist = r->next;
  }
  return (char*) r;
}
