/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:25:19 by cserdean          #+#    #+#             */
/*   Updated: 2017/02/09 13:25:21 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_nwords(char const *s, char c)
{
	int	i;
	int	nwords;

	i = 0;
	nwords = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			nwords++;
		else if (s[i] != c && s[i - 1] == c)
			nwords++;
		i++;
	}
	return (nwords);
}

static size_t	get_length(char const *s, char c, int x)
{
	size_t	len;

	len = 0;
	while (s[x] != '\0' && s[x] != c)
	{
		len++;
		x++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nwords;
	char	**new;

	if (!s || !c)
		return (NULL);
	new = (char **)malloc(sizeof(NULL) * (get_nwords(s, c) + 1));
	if (new)
	{
		i = 0;
		nwords = 0;
		while (s[i])
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				new[nwords++] = ft_strsub(s, i, get_length(s, c, i));
			while (s[i] != c && s[i])
				i++;
		}
		new[nwords] = 0;
	}
	return (new);
}
