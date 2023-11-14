#include "main.h"

/**
 * print_from_to - prints range of char
 *
 * @start: start input
 * @stop: stop input
 * @except: except input
 *
 * Return: int
*/

int print_from_to(char *start, char *stop, char *except)
{
	int s = 0;

	while (start <= stop)
	{
		if (start != except)
			s += _putchar(*start);
		start++;
	}
	return (s);
}

/**
 * print_rev - prints string in reverse order
 *
 * @ap: argument pointer
 * @par: parameters struct
 *
 * Return: int
*/

int print_rev(va_list ap, parameters_t *par)
{
	int l, s = 0;
	char *str = va_arg(ap, char);
	(void)par;

	if (str)
	{
		for (l = 0; *str; str++)
			l++;
		str--;
		for (; l > 0; len--, str--)
			s += _putchar(*str);
	}
	return (s);
}

/**
 * print_rot13 - prints string in rot13
 *
 * @ap: arguments pointer
 * @par: parameters struct input
 *
 * Return: int
*/

int print_rot13(va_list ap, parameters_t *par)
{
	int i, index;
	int count = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM     nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)par;

	i = 0;
	index = 0;

	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
