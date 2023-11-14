#include "main.h"

/**
 * get_specifier - finds format
 *
 * @s: format input
 *
 * Return: int
*/

int (*get_specifier(char *s))(va_list ap, parameters_t *par)
{
	specifier_t specifier[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL},
	};
	int i = 0;

	while (specifier[i].specifier)
	{
		if (*s == specifier[i].specifier[0])
			return (specifier[i].f);
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - finds format function
 *
 * @s: format string
 * @ap: atgument pointer
 * @par: parameters struct input
 *
 * Return: int
*/

int get_print_func(char *s, va_list ap, parameters_t *par)
{
	int (*f)(va_list, parameters_t *) = get_specifier(s);

	if (f)
		return (f(ap, par));
	return (0);
}

/**
 * get_flag - finds flag of the function
 *
 * @s: format string input
 * @par: parameters struct input
 *
 * Return: int
*/

int get_flag(char *s, parameters_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = par->plus_flag = 1;
			break;
		case ' ':
			i = par->space_flag = 1;
			break;
		case '#':
			i = par->hashtag_flag = 1;
			break;
		case '-':
			i = par->minus_flag = 1;
			break;
		case '0':
			i = par->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets width of format
 *
 * @s: format string
 * @par: parameters struct input
 * @ap: argument pointer
 *
 * Return: pointer
*/

char *get_width(char *s, parameters_t *par, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	par->width = d;
	return (s);
}
