/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:16:41 by cserdean          #+#    #+#             */
/*   Updated: 2017/01/31 20:22:19 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	lenorg;
	char	*new;

	if (!s)
		return (NULL);
	lenorg = ft_strlen(s);
	new = NULL;
	if ((start + len) <= lenorg)
	{
		new = ft_strnew(len);
		if (new)
		{
			new = ft_strncpy(new, s + start, len);
		}
	}
	return (new);
}
