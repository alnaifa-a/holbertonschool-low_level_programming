#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: the string to reverse
 *
 * Return: Nothing.
 */
void rev_string(char *s)
{
	int len;
	int start;
	int end;
	char tmp;

	len = 0;

	while (s[len] != '\0')
		len++;

	start = 0;
	end = len - 1;

	while (start < end)
	{
		tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		start++;
		end--;
	}
}
