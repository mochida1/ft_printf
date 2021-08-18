/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:36:02 by hmochida          #+#    #+#             */
/*   Updated: 2021/08/18 18:01:28 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	gethexlen(unsigned long long ln);
static char	*ascii_to_hex(char *ret, unsigned int caps);

char	*ft_uitoa16(unsigned long long n, unsigned int caps)
{
	unsigned long long	ln;
	char		*ret;

	ln = n;
	if (!n)
	{
		ret = ft_strdup("0");
		return (ret);
	}
	n = gethexlen(ln);
	ret = malloc((1 + n) * sizeof(char));
	if (!ret)
		return (0);
	ret[n--] = '\0';
	while (ln)
	{
		ret[n--] = '0' + (ln % 16);
		ln /= 16;
	}
	ret = ascii_to_hex(ret, caps);
	return (ret);
}

static size_t	gethexlen(unsigned long long ln)
{
	size_t	i;

	i = 0;
	while (ln)
	{
		ln /= 16;
		i++;
	}
	return (i);
}

static char	*ascii_to_hex(char *ret, unsigned int caps)
{
	int	i;

	i = 0;
	if (caps)
	{
		while (ret[i])
		{
			if (ret[i] > 57 && ret[i] < 64)
				ret[i] += 7;
			i++;
		}
	}
	else
	{
		while (ret[i])
		{
			if (ret[i] > 57 && ret[i] < 64)
				ret[i] += 39;
			i++;
		}
	}
	return (ret);
}
