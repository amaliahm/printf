#include "main.h"

/**
 * _puts - prints string
 *
 * @str: string input
 *
 * Return: nothing
*/

int _puts(char *str)
{
	char *i = str;

	while (*str)
		_putchar(*str++);
	return (str - i);
}

/**
 * _putchar - prints char
 *
 * @c: int input
 *
 * Return: int
*/

int _putchar(int c)
{
	static int a;

	static char buf(OUTPUT_BUF_SIZE);

	if (c == BUF_FLUSH || a >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}
