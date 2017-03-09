/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:24:54 by exam              #+#    #+#             */
/*   Updated: 2017/03/03 21:19:56 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nrlen_base(long long nr, int base)
{
	int len;

	len = 0;
	len = nr <= 0 ? len + 1 : len;
	while (nr != 0)
	{
		nr /= base;
		len++;
	}	
	return (len);
}

char			*ft_itoa_base(intmax_t value, int base)
{
	char		*s;
	char		*c;
	int			len;
	intmax_t	v;

	
	c = ft_strdup("0123456789ABCDEF");
	v = value;
	len = ft_nrlen_base(v, base);
	s = (char *)malloc(sizeof(char) * (len + 1));
	s[len--] = '\0';
	s[0] = v < 0 ? '-' : '0';
	v = v < 0 ? v * -1 : v;
	while (v != 0)
	{
		s[len--] = c[v % base];
		v /= base;
	}
	return (s);
}
