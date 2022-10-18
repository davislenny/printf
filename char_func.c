#include "main.h"
/**
 * print_c - prints a character format
 * @c: the character to print
 * Return: 1
 */
int print_c(va_list c)
{
	char h;

	h = (char)va_arg(c, int);
	putchar(h);
	return (1);
}

/**
 * print_s - print a string
 * @s: the string
 * Return: len(no of characters)
 */
int print_s(va_list s)
{
	int len;
	char *str = va_arg(s, char *);

	if (!str)
		str = "(nul)";
	for (len = 0; str[len]; len++)
		putchar(str[len]);
	return (len);
}
