/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:10:44 by cserdean          #+#    #+#             */
/*   Updated: 2017/03/03 21:19:17 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_get_uac(t_opt *opt, va_list args)
{
	if (ft_strstr(opt->flags, "hh") != NULL)
		return ((unsigned char)va_arg(args, int));
	if (ft_strstr(opt->flags, "ll"))
		return (va_arg(args, unsigned long long));
	if (ft_strchr(opt->flags, 'l') || opt->type == 'U')
		return (va_arg(args, unsigned long));
	if (ft_strchr(opt->flags, 'z'))
		return (va_arg(args, size_t));
	if (ft_strchr(opt->flags, 'j'))
		return (va_arg(args, uintmax_t));
	if (ft_strchr(opt->flags, 'h'))
		return ((unsigned short)va_arg(args, int));
	return (va_arg(args, unsigned int));
}

intmax_t	ft_get_ac(t_opt *opt, va_list args)
{
	if (ft_strstr(opt->flags, "hh") != NULL)
		return ((char)va_arg(args, int));
	if (ft_strstr(opt->flags, "ll"))
		return (va_arg(args, long long));
	if (ft_strchr(opt->flags, 'l') || opt->type == 'D')
		return (va_arg(args, long));
	if (ft_strchr(opt->flags, 'z'))
		return (va_arg(args, size_t));
	if (ft_strchr(opt->flags, 'j'))
		return (va_arg(args, intmax_t));
	if (ft_strchr(opt->flags, 'h'))
		return ((short)va_arg(args, int));
	return (va_arg(args, int));
}
