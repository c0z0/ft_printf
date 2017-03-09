/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:24:54 by exam              #+#    #+#             */
/*   Updated: 2017/03/01 23:08:41 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_u_nrlen_base(uintmax_t nr, int base)
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

char			*ft_u_itoa_base(uintmax_t value, int base)
{
	char		*s;
	char		*c;
	int			len;
	uintmax_t	v;

	c = ft_strdup("0123456789ABCDEF");
	v = value;
	if (v == 0)
		return (ft_strdup("0"));
	len = ft_u_nrlen_base(v, base);
	s = (char *)malloc(sizeof(char) * (len + 1));
	s[len--] = '\0';
	while (v != 0)
	{
		s[len--] = c[v % base];
		v /= base;
	}
	return (s);
}
