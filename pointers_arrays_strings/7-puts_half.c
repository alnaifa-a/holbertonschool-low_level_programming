#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: the string to print
 *
 * Return: Nothing.
 */
void puts_half(char *str)
{
	int len;
	int n;
	int i;

	len = 0;

	while (str[len] != '\0')
		len++;

	n = (len + 1) / 2;

	for (i = len - n; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}
