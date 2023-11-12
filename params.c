#include "main.h"

/**
 *
 * init_parameters - clears struct fields and reset buf
 * @parameters: the parameters struct
 * @ap: the argument pointer
 *
 *return void
 */

  void  init_parameters(parameters_t *p, va_list ap)
{
   parameters->unsign = 0;

   parameters->space_flag = 0;
   parameters->hashtag_flag = 0;
   parameters->zero_flag = 0;
   parameters->minus_flag = 0;

   parameters->width = 0;
   parameters->percision = UINT_MAX;

   parameters->h_modifier = 0;
   parameters->l_modifier = 0;
   (void)ap;





}
