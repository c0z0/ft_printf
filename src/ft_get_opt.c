/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:49:48 by cserdean          #+#    #+#             */
/*   Updated: 2017/03/03 18:15:33 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	return (c == '#' || c == '-' || c == ' ' || c == '+' || c == '0'
				|| c == 'h' || c == 'l' || c == 'z' || c == 'j');
}

t_opt	*ft_get_opt(char *f)
{
	int		i;
	t_opt	*opt;

	opt = (t_opt *)malloc(sizeof(t_opt));
	i = 0;
	opt->neg = 0;
	opt->min_fw = 0;
	opt->max_fw = -1;
	while (is_flag(f[i]))
		i++;
	opt->flags = ft_strnew(i);
	ft_strncpy(opt->flags, f, i);
	if (ft_isdigit(f[i]))
		opt->min_fw = ft_atoi(f + i);
	while (ft_isdigit(f[i]))
		i++;
	if (f[i] == '.')
		opt->max_fw = ft_atoi(f + i++ + 1);
	while (ft_isdigit(f[i]))
		i++;
	opt->type = f[i];
	opt->i = i;
	return (opt);
}
