/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:15:25 by hmochida          #+#    #+#             */
/*   Updated: 2021/08/18 03:28:11 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

size_t pchar(const int c)
{
	write (1, &c, 1);
	return(1);
}
