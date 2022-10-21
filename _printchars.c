#include "main.h"
/**
 * print_c - prints character
 * @c: the character
 * Return: 1
 */
int print_c(va_list c)
{
	char ch = (char)va_arg(c, int);

	putchar(ch);
	return (1);
}

/**
 * print_s - prints a string
 * @s: pointer to the string
 * Return: number of chars
 */
int print_s(va_list s)
{
	int count;
	char *str = va_arg(s, char *);

	if (!str)
		str = "(nul)";
	for (count = 0; str[count]; count++)
	{
		putchar(str[count]);
	}
	return (count);
}
/**
 * print_hex_c - prints a character's ASCII code value in hexadecimal
 * @c: the character
 * Return: number of chars
 */
int print_hex_c(char c)
{
	int count;
	char a[2];
	char diff = 'A' - ':';

	a[0] = c / 16;
	a[1] = c % 16;

	for (count = 0; count < 2; count++)
	{
		if (a[count] >= 10)
			putchar('0' + diff + a[count]);
		else
			putchar('0' + a[count]);
	}
	return (count);
}
/**
 * print_S - prints string; Non printable characters
 * (0 < ASCII value < 32 or >= 127)
 * are printed this way: \x, followed by the ASCII code value in hexadecimal
 * @S: the string
 * Return: number of chars
 */
int print_S(va_list S)
{
	unsigned int i;
	int count = 0;
	char *str = va_arg(S, char *);

	if (!str)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			putchar('\\');
			putchar('x');
			count += 2;
			count += print_hex_c(str[i]);
		}
		else
		{
			putchar(str[i]);
			count++;
		}
	}
	return (count);
}
/**
 * print_r - prints a string in rev
 * @r: the string
 * Return: number of chars
 */
int print_r(va_list r)
{
	int i, count = 0;
	char *str;

	str = va_arg(r, char *);
	if (!str)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		putchar(str[i]);
		count++;
	}
	return (count);
}
