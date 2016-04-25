#include <string.h>

void reverse (char string[])
{
	int i, j;
	char c;

	for (i = 0, j = strlen(string) - 1; i < j; i++, j--)
	{
		c = string[i];
		string[i] = string[j];
		string[j] = c;
	}
}
