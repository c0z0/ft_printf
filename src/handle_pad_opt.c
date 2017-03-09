/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pad_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:21:22 by cserdean          #+#    #+#             */
/*   Updated: 2017/03/03 18:13:35 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_pad_char(t_opt *opt)
{
	char	*pad;

	pad = ft_strnew(1);
	if (opt->type != 's' && ft_strchr(opt->flags, '0') &&
			ft_strchr(opt->flags, '-') == 0 && opt->max_fw == -1)
		pad[0] = '0';
	else
		pad[0] = ' ';
	return (pad);
}

int		get_pad_len(t_opt *opt)
{
	if (ft_strchr(opt->flags, '0') != 0)
	{
		if (opt->neg || ft_strchr(opt->flags, ' ') != 0
				|| ft_strchr(opt->flags, '+') != 0)
			opt->min_fw--;
		if (ft_strchr(opt->flags, '#') != 0)
			opt->min_fw = opt->type == 'o' ? opt->min_fw - 1 : opt->min_fw - 2;
	}
	return (opt->min_fw);
}
