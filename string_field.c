#include "main.h"

/**
 * get_precision - gets precision from format
 *
 * @p: format input
 * @par: parameters struct input
 * @ap: argument pointer
 *
 * Return : pointer
*/

char *get_precision(char *p, parameters_t *par, va_list ap)
{
	int a = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		a = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			a = a * 10 + (*p++ - '0');
	}
	par->precision = a;
	return (p);
}
