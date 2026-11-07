#include "main.h"

/**
 * times_table - Prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int row = 0;
	int col;
	int product;

	while (row < 10)
	{
		col = 0;
		while (col < 10)
		{
			product = row * col;
			if (col == 0)
				_putchar(product + '0');
			else
			{
				_putchar(',');
				_putchar(' ');
				if (product < 10)
				{
					_putchar(' ');
					_putchar(product + '0');
				}
				else
				{
					_putchar(product / 10 + '0');
					_putchar(product % 10 + '0');
				}
			}
			col++;
		}
		_putchar('\n');
		row++;
	}
}
