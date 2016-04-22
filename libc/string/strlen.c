#include <string.h>

size_t strlen(const uint8_t* string)
{
	size_t result = 0;
	while (string[result])
	{
		result++;
	}
	return result;
}
