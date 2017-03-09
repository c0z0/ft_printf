/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:10:15 by cserdean          #+#    #+#             */
/*   Updated: 2017/02/15 16:10:18 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			i;

	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	i = 0;
	if (pdest > psrc)
		while (i < len)
		{
			pdest[len - 1] = psrc[len - 1];
			len--;
		}
	else
		while (i < len)
		{
			pdest[i] = psrc[i];
			i++;
		}
	return (dest);
}
