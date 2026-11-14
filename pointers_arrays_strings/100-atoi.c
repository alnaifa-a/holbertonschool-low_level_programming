#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string
 *
 * Return: the converted integer, or 0 if no numbers
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int num;
	int found;

	i = 0;
	sign = 1;
	num = 0;
	found = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			num = (num * 10) - (s[i] - '0');
		}
		else if (found)
			break;
		else if (s[i] == '-')
			sign = -sign;

		i++;
	}

	if (!found)
		return (0);

	if (sign == 1)
		return (-num);

	return (num);
}
