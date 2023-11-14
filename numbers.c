#include "main.h"

/**
 * convert - convert function
 *
 * @num: int input
 * @base: int input
 * @flags: int input
 * @par: parameters struct input
 *
 * Return: pointer
*/

char *convert(long int num, int base, int flags, parameters_t *par)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)par;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	*ptr = '\0';
	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned number
 *
 * @ap: arguments pointer
 * @par: parameters struct
 *
 * Return: int
*/

int print_unsigned(va_list ap, parameters_t *par)
{
	unsigned long l;

	if (par->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (par->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	par->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, par), par));
}

/**
 * print_address - print address
 *
 * @ap: arguments pointer
 * @par: parameters struct
 *
 * Return: int
*/

int print_address(va_list ap, parameters_t *par)
{
	unsigned long int a = va_arg(ap, unsigned long int);
	char *s;

	if (!a)
		return (_puts("(nil)"));
	s = convert(a, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, par);
	*--s = 'x';
	*--s = "0";
	return (print_number(s, par));
}
