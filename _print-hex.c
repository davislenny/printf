#include "main.h"
/**
 * print_hex - prints unsigned int in hexadecimal (base 16)
 * @n: unsigned int to print
 * @c: number case, upper || lower
 * Return: count
 */
int print_hex(unsigned int n, unsigned int c)
{
	unsigned int i, m, sum;
	unsigned int array[8];
	char diff;
	int count;

	m = 268435456; /* 16 ^ 7 */
	if (c)
		diff = 'A' - ':';
	else
		diff = 'a' - ':';
	array[0] = n / m;
	for (i = 1; i < 8; i++)
	{
		m /= 16;
		array[i] = (n / m) % 16;
	}
	for (i = 0, sum = 0, count = 0; i < 8; i++)
	{
		sum += array[i];
		if (sum || i == 7)
		{
			if (array[i] < 10)
				putchar('0' + array[i]);
			else
				putchar('0' + diff + array[i]);
			count++;
		}
	}
	return (count);
}
/**
 * print_x - prints hex number in lowercase
 * @x: number
 * Return: count
 */
int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}
/**
 * print_X - prints hex number in uppercase
 * @X: number
 * Return: count
 */
int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}
