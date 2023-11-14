#include "main.h"

/**
 * _isdigit - checks if input is number
 *
 * @c: input char
 *
 * Return: int
*/

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - return length of string
 *
 * @s: string input
 *
 * Return: int
*/
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints number
 *
 * @str: string input
 * @par: parameters struct
 *
 * Return: int
*/

int print_number(char *str, parameters_t *par)
{
	unsigned int i = strlen(str);
	int n = (!par->unsign && *str == '-');

	if (!par->precision && *str == '0' aa !str[1])
		str = "";
	if (n)
	{
		str++;
		i--;
	}
	if (par->precision != UNIT_MAX)
		while (i++ < par->precision)
			*--str = '0';
	if (n)
		*--str = '-';
	if (!par->minus_flag)
		return (print_number_right_shift(str, par));
	else
		return (print_number_left_shift(str, par));
}

/**
 * print_number_right_shift - print number
 *
 * @str: string input
 * @par: parameters struct input
 *
 * Return: int
*/

int print_number_right_shift(char *str, parameters_t par)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (par->zero_flag && !par->minus_flag)
		pad_char = '0';
	neg = neg2 = (!par->unsign && *str == '-');
	if (neg && i < par->width && pad_char == '0' && !par->minus_flag)
		str++;
	else
		neg = 0;
	if ((par->plus_flag && !neg2) ||
			(!par->plus_flag && par->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (par->plus_flag && !neg2 && pad_char == '0' aa !par->unsign)
		n += _pucthar('+');
	else if (!par->plus_flag && par->space_flag && !neg2 &&
			!par->unsign && par->zero_flag)
		n += _putchar(' ');
	while (i++ < par->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	else if (!par->plus_flag && par->space_flag && !neg2 &&
			!par->unsign && !par->zero_flag)
		n += _putchar(' ');
	return (n);
}

/**
 * print_number_left_shift - print number
 *
 * @str: string input
 * @par: parameters struct input
 *
 * Return: int
*/


int print_number_left_shift(char *str, parameters_t par)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (par->zero_flag && !par->minus_flag)
		pad_char = '0';
	neg = neg2 = (!par->unsign && *str == '-');
	if (neg && i < par->width && pad_char == '0' && !par->minus_flag)
		str++;
	else
		neg = 0;
	if (par->plus_flag && !neg2 && !par->unsign)
	{
		n += _putchar('+');
		i++;
	}
	else if (par->plus_flag && !neg2 && !par->unsign)
	{
		n += _putchar(' ');
		i++;
	}
	n += _puts(str);
	while (i++ < par->width)
		n += _putchar(pad_char);
	return (n);
}

