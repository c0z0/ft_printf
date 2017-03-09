/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:52:58 by cserdean          #+#    #+#             */
/*   Updated: 2017/02/09 13:53:00 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_nsize(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		i;
	char	sign;
	char	*new;

	i = 0;
	sign = 0;
	if (n < 0)
		sign = 1;
	new = ft_strnew(get_nsize(n));
	if (!new)
		return (NULL);
	if (n == 0)
		new[0] = '0';
	while (n != 0)
	{
		new[i] = ft_abs(n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (sign)
		new[i] = '-';
	new = ft_strrev(new);
	return (new);
}
