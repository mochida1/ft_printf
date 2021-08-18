/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:41:00 by hmochida          #+#    #+#             */
/*   Updated: 2021/08/18 05:26:26 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pstr(char *c)
{
	size_t	i;
	size_t	end;

	if (!c)
		return (pstr_freeless("(null)"));
	i = 0;
	end = ft_strlen(c);
	while (i < end)
	{
		write (1, c, 1);
		c++;
		i++;
	}
	free(c - i);
	return (i);
}

size_t	pstr_freeless(const char *c)
{
	size_t	i;
	size_t	end;

	if (!c)
		return (pstr_freeless("(null)"));
	i = 0;
	end = ft_strlen(c);
	while (i < end)
	{
		write (1, c++, 1);
		i++;
	}
	return (i);
}
