#include "main.h"

/**
 * print_hex - prints uns hex nimber in lowercase
 *
 * @ap: arg pointer
 * @par: par struct
 *
 * Return : int
*/

int print_hex(va_list ap, parameters_t *par)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (par->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (par->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, par);
	if (par->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = 'O';
	}
	par->unsign = l;
	return (c += print_number(str, par));
}

/**
 * print_HEX - print hex n in uppercase
 *
 * @ap: agr pointer
 * @par: parameters struct
 *
 * Return: int
*/

int print_HEX(va_list ap, parameters_t *par)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (par->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (par->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 16, CONVERT_UNSIGNED, par);
	if (par->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = 'O';
	}
	par->unsign = l;
	return (c += print_number(str, par));
}

/**
 * print_binary - print unsigned binary n
 *
 * @ap: arg pointer
 * @par: par struct
 *
 * Return: int
*/

int print_binary(va_list ap, parameters_t *par)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, par);
	int c = 0;

	if (par->hashtag_flag && n)
		*--str = 'O';
	par->unsign = 1;
	return (c += print_number(str, par));
}

/**
 * print_octal - print unsigned n in octal
 *
 * @ap: arg pointer
 * @par: par struct
 *
 * Return: int
*/

int print_octal(va_list ap, parameters_t *par)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (par->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (par->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, par);
	if (par->hashtag_flag && l)
		*--str = 'O';
	par->unsign = 1;
	return (c += print_number(str, par));
}
