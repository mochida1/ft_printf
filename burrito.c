/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burrito.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 16:35:08 by hmochida          #+#    #+#             */
/*   Updated: 2021/08/18 23:23:55 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	burrito(const char *c, va_list ap)
{
	size_t	i;

	i = 0;
	if (*c == 'c')
		i += pchar(va_arg(ap, int));
	else if (*c == 's')
		i += pstr_freeless(va_arg(ap, char *));
	else if (*c == 'd' || *c == 'i')
		i += pstr(ft_itoa(va_arg(ap, int)));
	else if (*c == 'u')
		i += pstr(ft_uitoa(va_arg(ap, unsigned int)));
	else if (*c == 'x')
		i += pstr(ft_uitoa16(va_arg(ap, unsigned int), 0));
	else if (*c == 'X')
		i += pstr(ft_uitoa16(va_arg(ap, unsigned int), 1));
	else if (*c == 'p')
	{
		write (1, "0x", 2);
		i += 2 + pstr(ft_uitoa16(va_arg(ap, unsigned long long), 0));
	}
	else if (*c == '%')
		i += pchar(*c);
	return (i);
}

size_t	chk_burrito(const char *c)
{
	if (*c == 'c' || *c == 's' || *c == 'p' || *c == 'd' || *c == 'i'
		|| *c == 'u' || *c == 'x' || *c == 'X' || *c == '%')
		return (1);
	return (0);
}
