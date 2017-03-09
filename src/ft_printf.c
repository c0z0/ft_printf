/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:33:45 by cserdean          #+#    #+#             */
/*   Updated: 2017/03/03 21:38:14 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_flag_2(va_list args, int *printed, t_opt *opt)
{
	if (opt->type == 'S')
		handle_cap_s(opt, args, printed);
	else if (opt->type == 'u' || opt->type == 'U')
		handle_un(opt, args, printed);
	return (opt->i + 2);
}

int		handle_flag(char *f, va_list args, int *printed)
{
	t_opt	*opt;

	opt = ft_get_opt(f);
	if (opt->type == 's')
		handle_s(opt, args, printed);
	else if (opt->type == 'd' || opt->type == 'i' || opt->type == 'D')
		handle_d(opt, args, printed);
	else if (opt->type == '%')
		put_s(opt, "%", printed);
	else if (opt->type == 'c')
		handle_c(opt, args, printed);
	else if (opt->type == 'X')
		handle_capx(opt, args, printed);
	else if (opt->type == 'x')
		handle_x(opt, args, printed);
	else if (opt->type == 'o')
		handle_o(opt, args, printed);
	else if (opt->type == 'p')
		handle_p(opt, args, printed);
	else if (opt->type == 'C')
		handle_cap_c(opt, args, printed);
	else
		return (handle_flag_2(args, printed, opt));
	return (opt->i + 2);
}

int		handle_escape(char *f)
{
	if (f[1] == 'n')
		ft_putchar('\n');
	else if (f[1] == 'a')
		ft_putchar('\a');
	else if (f[1] == 't')
		ft_putchar('\t');
	else if (f[1] == 'r')
		ft_putchar('\r');
	else if (f[1] == '\b')
		ft_putchar('\b');
	else if (f[1] == '\\')
		ft_putchar('\\');
	else if (f[1] == '\'')
		ft_putchar('\'');
	return (2);
}

int		ft_printf(char *format, ...)
{
	int		printed;
	int		i;
	va_list	args;

	printed = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += handle_flag(format + i + 1, args, &printed);
		else if (format[i] == '\\')
		{
			printed++;
			i += handle_escape(format + i);
		}
		else
		{
			printed++;
			ft_putchar(format[i++]);
		}
	}
	va_end(args);
	return (printed);
}
