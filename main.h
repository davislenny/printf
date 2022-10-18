#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * struct print - structure to print a specified format
 * @c: pointer to a format specifier
 * @func: pointer to the fuction that prints the format
 */
typedef struct print
{
	char *c;
	int (*func)(va_list);
} print_t;

int print_c(va_list c);
int print_s(va_list s);
int (*find_format_func(const char *format))(va_list);
int _printf(const char *format, ...);

#endif /* _PRINTF_H */
