/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:36:35 by hmochida          #+#    #+#             */
/*   Updated: 2021/08/18 17:41:59 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

size_t	burrito(const char *c, va_list ap);
size_t	chk_burrito (const char *c);
size_t	pchar(const int c);
size_t	pstr(char *c);
size_t	pstr_freeless(const char *c);
int		ft_printf(const char *inp, ...);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_uitoa16(unsigned long long n, unsigned int caps);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);

#endif
