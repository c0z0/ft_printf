/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:55:23 by cserdean          #+#    #+#             */
/*   Updated: 2017/02/09 13:55:26 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t written;

	written = 0;
	while (written < len)
	{
		((char *)b)[written] = (unsigned char)c;
		written++;
	}
	return (b);
}
