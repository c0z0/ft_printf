/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:04:09 by cserdean          #+#    #+#             */
/*   Updated: 2017/02/15 16:04:10 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpy;

	i = 0;
	cpy = (unsigned char *)s;
	if (n > 0)
		while (i < n)
		{
			if (cpy[i] == (unsigned char)c)
				return ((void *)&cpy[i]);
			i++;
		}
	return (NULL);
}
