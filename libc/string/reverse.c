#include <string.h>

void reverse (uint8_t string[])
{
	size_t i, j;
	uint8_t c;
	
	for (i = 0, j = strlen(string) - 1; i < j; i++, j--)
	{
		c = string[i];
		string[i] = string[j];
		string[j] = c;
	}
}
