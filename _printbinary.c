#include "main.h"
/**
 * print_bin - prints unsigned int in binary
 * @num: the int
 * Return: count
 */
int print_bin(va_list num)
{
	unsigned int i, n, m, sum;
	unsigned int array[32];
	int count;

	n = va_arg(num, unsigned int);
	m = 2147483649;/* max value of unsigned int = 2^31*/
	array[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		array[i] = (n / m) % 2;
	}
	i = sum = count = 0;
	for (; i < 32; i++)
	{
		sum += array[i];
		if (sum || i == 31)
		{
			putchar('0' + array[i]);
			count++;
		}
	}
	return (count);
}
