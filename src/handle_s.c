/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 21:49:22 by cserdean          #+#    #+#             */
/*   Updated: 2017/03/03 21:30:10 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_s(t_opt *opt, char *s, int *printed)
{
	handle_prec(opt, &s);
	if (ft_strchr(opt->flags, '0') != 0)
	{
		handle_pad(opt, &s);
		handle_sign(opt, &s);
		handle_hash(opt, &s);
	}
	else
	{
		handle_hash(opt, &s);
		handle_sign(opt, &s);
		handle_pad(opt, &s);
	}
	ft_putstr(s);
	*printed += ft_strlen(s);
}

void	handle_s(t_opt *opt, va_list args, int *printed)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
		put_s(opt, "(null)", printed);
	else
		put_s(opt, s, printed);
}

void	handle_d(t_opt *opt, va_list args, int *printed)
{
	char		*s;
	intmax_t	n;

	n = ft_get_ac(opt, args);
	if (n < 0)
	{
		n *= -1;
		opt->neg = 1;
	}
	if (n < 0)
		s = ft_u_itoa_base(n, 10);
	else
		s = ft_itoa_base(n, 10);
	put_s(opt, s, printed);
}

void	handle_c(t_opt *opt, va_list args, int *printed)
{
	char	c;
	char	*s;

	c = va_arg(args, int);
	if (c == 0)
	{
		*printed += 1;
		opt->min_fw--;
	}
	s = ft_strnew(1);
	s[0] = c;
	put_s(opt, s, printed);
}

void	handle_x(t_opt *opt, va_list args, int *printed)
{
	char		*s;
	uintmax_t	n;

	n = ft_get_uac(opt, args);
	s = ft_u_itoa_base(n, 16);
	s = ft_strtolower(s);
	put_s(opt, s, printed);
}
