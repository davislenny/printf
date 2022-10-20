#include "main.h"
/**
 * print_di - prints decimal (base 10) number
 * @d: the number
 * Return: count
 */
int print_di(va_list d)
{
	int n, div = 1, len = 0;
	unsigned int m;

	n = va_arg(d, int);

	if (n < 0)
	{
		len += putchar('-');
		m = n * -1;
	}
	else
		m = n;
	while (m / div > 9)
		div *= 10;
	while (div != 0)
	{
		len += putchar(m / div + '0');
		m %= div;
		div /= 10;
	}
	return (len);
}
/**
 * print_u - prints unsigned int (base 10)
 * @u: the int
 * Return: count
 */
int print_u(va_list u)
{
	unsigned int i, n, m, sum;
	unsigned int array[10];
	int count;

	n = va_arg(u, unsigned int);
	m = 1000000000;/* 10 ^ 9 */
	array[0] = n / m;
	for (i = 1; i < 10; i++)
	{
		m /= 10;
		array[i] = (n / m) % 10;
	}
	for (i = 0, sum = 0, count = 0; i < 10; i++)
	{
		sum += array[i];
		if (sum || i == 9)
		{
			putchar('0' + array[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_o - prints unsigned int in octal (base 8)
 * @o: the unsigned int
 * Return: count
 */
int print_o(va_list o)
{
	int i, count = 0;
	int *array;
	unsigned int n = va_arg(o, unsigned int);
	unsigned int m = n;

	while (n / 8 != 0)
	{
		n /= 8;
		count++;
	}
	count++;
	array = malloc(count * sizeof(int));
	if (!array)
	{
		free(array);
		return (0);
	}
	for (i = 0; i < count; i++)
	{
		array[i] = m % 8;
		m /= 8;
	}
	for (i = count - 1; i >= 0; i--)
	{
		putchar(array[i] + '0');
	}
	free(array);
	return (count);
}
