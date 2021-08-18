/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:06:38 by hmochida          #+#    #+#             */
/*   Updated: 2021/08/17 20:54:17 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getuintlen(unsigned int n)
{
	int		i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

/*
** i → index; i
*/
char	*ft_uitoa(unsigned int n)
{
	char	*s;
	int		i;

	i = getuintlen(n);
	s = malloc(i + 1 * (sizeof(char)));
	if (!s)
		return (0);
	s[i--] = '\0';
	while (n >= 10)
	{
		s[i--] = '0' + (n % 10);
		n /= 10;
	}
	s[i] = '0' + (n % 10);
	return (s);
}
