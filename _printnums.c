#include "main.h"
/**
 * print_di - prints decimal (base 10) number
 * @d: the number
 * Return: count
 */
int print_di(va_list d)
{
	int i, m, n, sum, count;
	int a[10];
	
	n = va_arg(d, int);
	count = 0;
	m = 1000000000;
	a[0] = n / m;
	for (i = 1; i < 10; i++)
	{
		m /= 10;
		a[i] = (n/ m) % 10;
	}
	if (n < 0)
	{
		putchar('-');
		count++;
		for (i = 0; i < 10; i++)
			a[i] *= -1;
	}
	for (i = 0, sum = 0; i < 10; i++)
	{
		sum += a[i];
		if (sum != 0 || i == 9)
		{
			putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
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
