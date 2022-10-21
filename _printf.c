#include "main.h"
/**
 * get_func - picks correct function
 * @format: pointer to format char
 * Return: pointer to correct function
 */
int (*get_func(const char *format))(va_list)
{
	print_t op[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_di},
		{"i", print_di},
		{"b", print_bin},
		{"x", print_x},
		{"X", print_X},
		{"o", print_o},
		{"u", print_u},
		{NULL, NULL}
	};

	int i;

	for (i = 0; op[i].c != NULL; i++)
	{
		if (*(op[i].c) == *format)
		{
			break;
		}
	}
	return (op[i].func);
}
/**
 * _printf - printf-like function
 * @format: format specifier
 * Return: number of chars
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;

	va_list args;
	int (*func)(va_list);

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		func = get_func(&format[i + 1]);
		if (func != NULL)
		{
			count += func(args);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(args);
	return (count);
}
