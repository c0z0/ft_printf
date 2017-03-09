/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:13:01 by cserdean          #+#    #+#             */
/*   Updated: 2017/01/31 18:16:15 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t lend;
	size_t lens;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	i = 0;
	if (size < lend)
		return (size + lens);
	while (src[i] != '\0' && (lend + i + 1) < size)
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + i] = '\0';
	return (lend + lens);
}
