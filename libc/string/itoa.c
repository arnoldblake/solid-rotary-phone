// Blake Arnold 11-4-2016
// Implementation of itoa, Integer to ASCII

#include <string.h>

void itoa(int n, char s[], int radix)
{
	int i, sign;

	if ((sign = n) < 0)
	{
		n = -n;
	}
	i = 0;
	do
	{
		s[i] = n % radix + '0';
		switch (radix) {
			case 16:
				if (s[i] > 57)
				{
					s[i] += 7;
				}
				break;
		}
		i++;
	}
	while ((n /= radix) > 0);
	if (sign < 0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}
