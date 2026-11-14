#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the first element of the matrix
 * @size: the width and height of the matrix
 *
 * Return: Nothing.
 */
void print_diagsums(int *a, int size)
{
	int i;
	int main_sum;
	int anti_sum;

	main_sum = 0;
	anti_sum = 0;

	for (i = 0; i < size; i++)
	{
		main_sum += a[i * size + i];
		anti_sum += a[i * size + (size - 1 - i)];
	}

	printf("%d, %d\n", main_sum, anti_sum);
}
