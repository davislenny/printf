#include "main.h"
/**
 * print_c - prints character
 * @c: the character
 * Return: number of chars
 */
int print_c(va_list c)
{
	return (putchar(va_arg(c, int)));
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

	count = 0;
	while (str[count] != '\0')
		count += putchar(str[count]);
	return (count);
}
