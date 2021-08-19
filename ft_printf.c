/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:10:13 by hmochida          #+#    #+#             */
/*   Updated: 2021/08/18 23:30:26 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *inp, ...)
{
	size_t		ccount;
	va_list		ap;

	va_start (ap, inp);
	ccount = 0;
	while (*inp)
	{
		if (*inp == '%')
		{
			if (chk_burrito(inp + 1))
			{
				ccount += burrito(inp + 1, ap);
				inp += 2;
			}
		}
		else
		{
			pchar(*inp);
			inp++;
			ccount++;
		}
	}
	va_end(ap);
	return (ccount);
}
