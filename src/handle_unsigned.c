/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:06:35 by cserdean          #+#    #+#             */
/*   Updated: 2017/03/03 21:42:59 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_un(t_opt *opt, va_list args, int *printed)
{
	char		*s;
	uintmax_t	n;

	n = ft_get_uac(opt, args);
	s = ft_u_itoa_base(n, 10);
	put_s(opt, s, printed);
}

void	put_ws(t_opt *opt, wchar_t *s, int *printed)
{
	char	pad;
	int		padlen;

	pad = ' ';
	if (ft_strchr(opt->flags, '0') != 0)
		pad = '0';
	padlen = opt->min_fw - ft_wstrlen(s);
	while (padlen-- > 0 && ft_strchr(opt->flags, '-') == 0)
	{
		(*printed)++;
		ft_putwchar_fd(pad, 0);
	}
	padlen = 0;
	opt->max_fw = opt->max_fw > 0 ? opt->max_fw : ft_wstrlen(s);
	while (s[padlen] != '\0' && padlen < opt->max_fw)
	{
		(*printed)++;
		ft_putwchar_fd(s[padlen++], 0);
	}
	while (padlen++ < opt->min_fw && ft_strchr(opt->flags, '-') != 0)
	{
		(*printed)++;
		ft_putwchar_fd(pad, 0);
	}
}

void	handle_cap_c(t_opt *opt, va_list args, int *printed)
{
	wchar_t	*c;

	c = (wchar_t *)malloc(sizeof(wchar_t) * 2);
	c[1] = '\0';
	c[0] = va_arg(args, int);
	put_ws(opt, c, printed);
}

void	handle_cap_s(t_opt *opt, va_list args, int *printed)
{
	wchar_t	*c;

	c = va_arg(args, int *);
	put_ws(opt, c, printed);
}
