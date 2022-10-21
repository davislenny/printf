#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 * struct print - print structure
 * @c: character
 * @func: function pointer
 */
typedef struct print
{
	char *c;
	int (*func)(va_list);
} print_t;

int _printf(const char *format, ...);
int (*get_func(const char *format))(va_list);
int print_c(va_list c);
int print_s(va_list s);
int print_di(va_list d);
int print_bin(va_list num);
int print_hex(unsigned int n, unsigned int c);
int print_x(va_list x);
int print_X(va_list X);
int print_o(va_list o);
int print_u(va_list u);
int print_hex_c(char c);
int print_S(va_list S);
int print_r(va_list r);


#endif /* MAIN_H */
