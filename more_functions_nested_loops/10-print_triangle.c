#include "main.h"

/**
 * print_triangle - Prints a triangle, followed by a new line
 * @size: The size of the triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
	int row = 1;
	int col;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	while (row <= size)
	{
		col = 1;
		while (col <= size)
		{
			if (col <= size - row)
				_putchar(' ');
			else
				_putchar('#');
			col++;
		}
		_putchar('\n');
		row++;
	}
