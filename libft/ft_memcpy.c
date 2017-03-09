/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:56:01 by cserdean          #+#    #+#             */
/*   Updated: 2017/02/09 13:57:58 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t copied;

	copied = 0;
	while (copied < n)
	{
		((unsigned char *)dst)[copied] = ((unsigned char *)src)[copied];
		copied++;
	}
	return (dst);
}
