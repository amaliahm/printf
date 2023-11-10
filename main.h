#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMETERS_INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - arguments structure
 *
 * @unsign: int input
 * @plus_flag: int input
 * @space_flag: int input
 * @hashtag_flag: int input
 * @zero_flag: int input
 * @minus_flag: int input
 * @width: argument
 * @precision: argument
 * @h_modifier: int input
 * @l_modifier: in input
*/

typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} parameters_t;

/**
 * struct specifier - struct token
 *
 * @specifier: formate
 * @f: function
*/

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, parameters_t *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);
int print_char(va_list ap, parameters_t *p);
int print_int(va_list ap, parameters_t *p);
int print_string(va_list ap, parameters_t *p);
int print_percent(va_list ap, parameters_t *p);
int print_S(va_list ap, parameters_t *p);

char *convert(long int num, int base, int flags, parameters_t *p);
int print_unsigned(va_list ap, parameters_t *p);
int print_address(va_list ap, parameters_t *p);

int (*get_specifier(char *s))(va_list ap, parameters_t *p);
int get_print_func(char *s, va_list ap, parameters_t *p);
int get_flag(char *s, parameters_t *p);
int get_modifier(char *s, parameters_t *p);
char *get_width(char *s, parameters_t *p, va_list ap);

int print_hex(va_list ap, parameters_t *p);
int print_HEX(va_list ap, parameters_t *p);
int print_binary(va_list ap, parameters_t *p);
int print_octal(va_list ap, parameters_t *p);

int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, parameters_t *p);
int print_rot13(va_list ap, parameters_t *p);

int _isdigit(int c);
int _strlen(char *c);
int print_number(char *str, parameters_t *p);
int print_number_right_shift(char *str, parameters_t *p);
int print_number_left_shift(char *str, parameters_t *p);

void init_parameters(parameters_t *p, va_list ap);
void *get_precision(char *g, parameters_t *p, va_list ap);

int _printf(const char *format, ...);

#endif
