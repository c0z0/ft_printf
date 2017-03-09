/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:06:48 by cserdean          #+#    #+#             */
/*   Updated: 2017/02/09 13:53:30 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int pos;
	int len;

	len = ft_strlen(little);
	i = 0;
	pos = 0;
	if (len == 0)
		return ((char *)big);
	while (big[i])
	{
		while (little[pos] == big[i + pos])
		{
			if (pos == len - 1)
				return ((char *)big + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}
