#include "main.h"
/**
 * print_d - print a decimal (base 10) number
 * @d: the number
 * Return: number of chars
 */
int print_d(va_list d)
{
	int i, x, y, sum, count;
	int array[10];

	x = va_arg(d, int);
	y = 1000000000;
	array[0] = x / y;

	for (i = 1; i < 10; i++)
	{
		y /= 10;
		array[i] = (x / y) % 10;
	}
	count = 0;
	if (x < 10)
	{
		putchar('-');
		count++;
		for (i = 0; i < 10; i++)
			array[i] *= -1;
	}
	for (i = 0, sum = 0; i < 10; i++)
	{
		sum += array[i];
		if (sum != 0 || i == 9)
		{
			putchar('0' + array[i]);
			count++;
		}
	}
	return (count);
}
