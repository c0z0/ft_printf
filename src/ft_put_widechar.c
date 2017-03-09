/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_widechar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:54:58 by cserdean          #+#    #+#             */
/*   Updated: 2017/03/03 18:24:20 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "ft_printf.h"

int		ft_wstrlen(wchar_t *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		nbr_bits(unsigned int nbr)
{
	int i;

	i = 1;
	while ((nbr = nbr >> 1))
		i++;
	return (i);
}

void	ft_putwchar_fd(wchar_t wchar, int fd)
{
	unsigned int	ch;
	int				n;

	ch = (unsigned int)wchar;
	n = nbr_bits(ch);
	if (n > 7)
	{
		if (n > 11)
		{
			if (n > 16)
			{
				ft_putchar_fd(((ch >> 18) & 7) | 240, fd);
				ft_putchar_fd(((ch >> 12) & 63) | 128, fd);
			}
			else
				ft_putchar_fd(((ch >> 12) & 15) | 224, fd);
			ft_putchar_fd(((ch >> 6) & 63) | 128, fd);
		}
		else
			ft_putchar_fd(((ch >> 6) & 31) | 192, fd);
		ft_putchar_fd((ch & 63) | 128, fd);
	}
	else
		ft_putchar_fd(ch, fd);
}
