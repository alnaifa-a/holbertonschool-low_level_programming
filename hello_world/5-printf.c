#include <stdio.h>

/**
 * main - print the size of various types on the computer it is compiled and run on
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(char));
    printf("Size of an int: %lu byte(s)\n", (unsigned long)sizeof(int));
	printf("Size of a float: %lu byte(s)\n", 
        (unsigned long)sizeof(float));
	printf("Size of a double: %lu byte(s)\n", (unsigned long)sizeof(double));
	return (0);
}
