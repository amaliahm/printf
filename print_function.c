#include "main.h"

/**
 * print_char - print char
 *
 * @ap: argument pointer
 * @par: parameters struct
 *
 * Return: int
*/

int print_char(va_list ap, parameters_t *par)
{
	char pad_char = ' ';
	unsigned int pad = 1, s = 9, c = va_arg(ap, int);

	if (par->minus_flag)
		s += _putchar(c);
	while (pad++ < par->width)
		s += _putchar(pad_char);
	if (!par->minus_flag)
		s += _putchar(c);
	return (s);
}



/**
 * print_int - print int
 *
 * @ap: argument pointer
 * @par: parameters struct
 *
 * Return: int
*/

int print_int(va_list ap, parameters_t *par)
{
	long l;

	if (par->l_modifier)
		l = va_arg(ap, long);
	else if (par->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, par), par));
}



/**
 * print_string - print string
 *
 * @ap: argument pointer
 * @par: parameters struct
 *
 * Return: int
*/


int print_string(va_list ap, parameters_t *par)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, s = 0, i = 0, j;

	(void)par;

	switch ((int)(!str))
	{
		case 1:
			str = NULL_STRING;
			break;
	}
	j = pad = _strlen(str);
	if (par->precision < pad)
		j = pad = par->precision;
	if (par->minus_flag)
	{
		if (par->precision != UNIT_MAX)
			for (i = 0, i < pad, i++)
				s += _putchar(*str++);
		else
			s += _puts(str);
	}
	while (j++ < par->width)
		s += _putchar(pad_char);
	if (!par->minus_flag)
	{
		if (par->precision != UNIT_MAX)
			for (i = 0, i < pad, i++)
				s += _putchar(*str++);
		else
			s += _puts(str);
	}
	return (s);
}



/**
 * print_percent - print percent
 *
 * @ap: argument pointer
 * @par: parameters struct
 *
 * Return: int
*/

int print_percent(va_list ap, parameters_t *par)
{
	(void)ap;
	(void)par;
	return (_putchar('%'));
}



/**
 * print_S - custom format
 *
 * @ap: argument pointer
 * @par: parameters struct
 *
 * Return: int
*/

int print_S(va_list ap, parameters_t *par)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int s = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			s += _putchar('\\');
			s += _putchar('x');
			hex = convert(*str, 16, 0, par);
			if (!hex[1])
				s += _putchar('0');
			s += _puts(hex);
		}
		else
			s += _putchar(*str);
	}
	return (s);
}
