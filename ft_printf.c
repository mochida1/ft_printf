/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:10:13 by hmochida          #+#    #+#             */
/*   Updated: 2021/08/18 05:00:05 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *inp, ...)
{
	size_t ccount;
	va_list ap;
	va_start (ap, inp);

	ccount = 0;
//adicionar proteção contra stackoverflow de parametros recebidos


/*
pra puxar da va_list:
strtoprint = va_arg(ap, char *);
*/
while (*inp) // pega inp
{
	if (*inp == '%')
	{
		if (chk_burrito(inp + 1))
		{
			ccount += burrito(inp + 1, ap);
			inp += 2;
		}
		else
		{
		write (1, "%", 1);
		inp++;
		ccount++;
		}
	}
	ccount += pchar(*inp);
	inp++;
}

// se %, checa %+1 se %, printa %
// senão, se cspdiux printa a conversao
// vai writando os chars até \0


/*
The C library macro void va_end(va_list ap) allows a function with variable arguments which used the va_start macro to return.
If va_end is not called before returning from the function, the result is undefined.
*/
va_end(ap);
return (ccount);
}


/*
• %c print a single character.													-ok
• %s print a string of characters.												-ok
• %p The void * pointer argument is printed in hexadecimal. 0x+%x				-ok
• %d print a decimal (base 10) number.											-ok (pstr+itoa)
• %i print an integer in base 10.												-ok (pstr+itoa)
• %u print an unsigned decimal (base 10) number.								-ok (pstr+uitoa)
• %x print an UNSIGNED INT in hexadecimal (base 16). 11259375→abcdef			-ok
• %X print an UNSIGNED INT in hexadecimal (base 16) captalized. 11259375→ABCDEF -ok
• %% print a percent sign.														-oooook

 ----------error handling-----------
format specificer diferente do data type -> tenta ler da mesma forma que o speicifier pede;
format specifier invalido -> ignora o % e printa o proximo caractere (igual a %%)
*/

// ffffffffffff = 281474976710655 = FF *6
// 7FFFFFFFFFFFFFFF = 9223372036854775807 = LONG_MAX
