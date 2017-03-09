/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:57:33 by cserdean          #+#    #+#             */
/*   Updated: 2017/02/09 16:43:00 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i]) && (i < n))
		i++;
	if (i == n)
		return (0);
	return (((unsigned char)s1[i]) - (unsigned char)(s2[i]));
}
