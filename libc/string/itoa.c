// Blake Arnold 11-4-2016
// Implementation of itoa, Integer to ASCII

#include <string.h>

void itoa(int32_t n, uint8_t s[])
{
	size_t i;
	uint32_t sign;
	
	if ((sign = n) < 0)
	{
		n = -n;
	}
	i = 0;
	do
	{
		s[i++] = n % 10 + '0';
	}
	while ((n /= 10) > 0);
	if (sign < 0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);	
}
