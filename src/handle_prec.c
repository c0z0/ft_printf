/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:37:41 by cserdean          #+#    #+#             */
/*   Updated: 2017/03/03 19:30:22 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_prec(t_opt *opt, char **s)
{
	char	*c;

	if (opt->max_fw > 0 && opt->type != 'c')
	{
		if (opt->type == 's' && opt->max_fw < (int)ft_strlen(*s))
		{
			c = ft_strnew(opt->max_fw);
			ft_strncpy(c, *s, opt->max_fw);
			*s = c;
		}
		else if (opt->type != 's')
		{
			while ((int)ft_strlen(*s) < opt->max_fw)
				*s = ft_strjoin("0", *s);
		}
	}
	else if (opt->max_fw == 0 && ft_strcmp("0", *s) == 0)
		ft_strclr(*s);
}

void	handle_pad(t_opt *opt, char **s)
{
	char	*pad;

	pad = get_pad_char(opt);
	if (opt->min_fw > 0)
	{
		opt->min_fw = get_pad_len(opt);
		while ((int)ft_strlen(*s) < opt->min_fw)
			if (ft_strchr(opt->flags, '-') != 0)
				*s = ft_strjoin(*s, pad);
			else
				*s = ft_strjoin(pad, *s);
		if (opt->type == 's')
		{
			while ((int)ft_strlen(*s) < opt->min_fw)
			{
				*s = ft_strjoin(pad, *s);
			}
		}
	}
}

void	handle_hash(t_opt *opt, char **s)
{
	if (ft_strchr(opt->flags, '#') && (ft_strlen(*s) != 0
		|| opt->type == 'o') && ft_strcmp(*s, "0") != 0)
	{
		if (opt->type == 'x')
			*s = ft_strjoin("0x", *s);
		else if (opt->type == 'X')
			*s = ft_strjoin("0X", *s);
		else if (opt->type == 'o')
			*s = ft_strjoin("0", *s);
	}
}

void	handle_sign(t_opt *opt, char **s)
{
	if (opt->type == 'd' || opt->type == 'D' || opt->type == 'i')
	{
		if (opt->neg)
			*s = ft_strjoin("-", *s);
		else if (ft_strchr(opt->flags, '+') != 0)
			*s = ft_strjoin("+", *s);
		else if (ft_strchr(opt->flags, ' ') != 0)
			*s = ft_strjoin(" ", *s);
	}
}
