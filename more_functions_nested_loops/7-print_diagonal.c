#include "main.h"

/**
 * print_diagonal - Draws a diagonal line on the terminal
 * @n: The number of times the character \ should be printed
 *
 * Return: void
 */
void print_diagonal(int n)
{
	int i = 0;
	int space;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}
	while (i < n)
	{
		space = 0;
		while (space < i)
		{
			_putchar(' ');
			space++;
		}
		_putchar('\\');
		_putchar('\n');
		i++;
	}
}
