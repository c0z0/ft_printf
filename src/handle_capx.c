/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_capx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 23:25:30 by cserdean          #+#    #+#             */
/*   Updated: 2017/03/02 09:36:25 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_capx(t_opt *opt, va_list args, int *printed)
{
	char			*s;
	uintmax_t		n;

	n = ft_get_uac(opt, args);
	s = ft_u_itoa_base(n, 16);
	put_s(opt, s, printed);
}

void	handle_o(t_opt *opt, va_list args, int *printed)
{
	char		*s;
	uintmax_t	n;

	n = ft_get_uac(opt, args);
	s = ft_u_itoa_base(n, 8);
	put_s(opt, s, printed);
}

void	handle_p(t_opt *opt, va_list args, int *printed)
{
	uintmax_t	p;
	char		*s;

	p = va_arg(args, uintmax_t);
	s = ft_strtolower(ft_u_itoa_base(p, 16));
	put_s(opt, ft_strjoin("0x", s), printed);
}
