#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to scan
 * @accept: the set of accepted bytes
 *
 * Return: number of bytes in the initial segment of s made only of
 * bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	int j;
	int found;

	count = 0;

	while (s[count] != '\0')
	{
		found = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[count] == accept[j])
			{
				found = 1;
				break;
			}
		}

		if (!found)
			break;

		count++;
	}

	return (count);
}
