/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:23:53 by cserdean          #+#    #+#             */
/*   Updated: 2017/01/31 20:31:18 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;

	new = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		new = ft_strnew(len);
		if (new)
		{
			ft_strcpy(new, s1);
			ft_strcat(new, s2);
		}
	}
	return (new);
}
