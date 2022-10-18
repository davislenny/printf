#include "main.h"
/**
 * find_format_func - selects the right format function
 * @format: specified format
 * Return: pointer to the correct format
 */
int (*find_format_func(const char *format))(va_list)
{
	unsigned int i;
	print_t f[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
/*		{"i", print_d},*/
		{NULL, NULL}
	};

	for (i = 0; f[i].c != NULL; i++)
	{
		if (*f[i].c == *format)
			break;
	}
	return (f[i].func);
}

/**
 * _printf - produces output according to a format
 * @format: pointer to format specified
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i, count;

	va_list(args);
	int (*f)(va_list);

	if (!format)
		return (-1);
	va_start(args, format);
	i = count = 0;
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		f = find_format_func(&format[i + 1]);
		if (f != NULL)
		{
			count += f(args);
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
