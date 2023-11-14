#include "main.h"

/**
 * init_parameters - clears struct and buf
 *
 * @p: parameters struct input
 * @ap: pointer input
 *
 * Return: nothing
*/

void init_parameters(parameters_t *p, va_list ap)
{
	p->unsign = 0;
	p->plus_flag = 0;
	p->space_flag = 0;
	p->hashtag_flag = 0;
	p->zero_flag = 0;
	p->minus_flag = 0;
	p->width = 0;
	p->precision = 0;
	p->h_modifier = 0;
	p->l_modifier = 0;
	(void)ap;
}
