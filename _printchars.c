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
