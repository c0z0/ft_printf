/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserdean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:39:49 by cserdean          #+#    #+#             */
/*   Updated: 2017/03/03 18:12:51 by cserdean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include <stdio.h>
# include <wchar.h>

typedef struct	s_opt
{
	char		*flags;
	int			min_fw;
	int			max_fw;
	char		type;
	int			i;
	int			neg;
}				t_opt;

char			*get_pad_char(t_opt *opt);
int				get_pad_len(t_opt *opt);
void			handle_sign(t_opt *opt, char **s);
void			handle_prec(t_opt *opt, char **s);
void			handle_hash(t_opt *opt, char **s);
void			handle_pad(t_opt *opt, char **s);
int				ft_wstrlen(wchar_t *s);
void			ft_putwchar_fd(wchar_t wchar, int fd);
void			handle_s(t_opt *opt, va_list args, int *printed);
void			handle_p(t_opt *opt, va_list args, int *printed);
void			put_s(t_opt *opt, char *s, int *printed);
int				ft_printf(char *format, ...);
t_opt			*ft_get_opt(char *f);
void			handle_d(t_opt *opt, va_list args, int *printed);
void			handle_c(t_opt *opt, va_list args, int *printed);
void			handle_x(t_opt *opt, va_list args, int *printed);
void			handle_capx(t_opt *opt, va_list args, int *printed);
void			handle_o(t_opt *opt, va_list args, int *printed);
void			handle_un(t_opt *opt, va_list args, int *printed);
intmax_t		ft_get_ac(t_opt *opt, va_list args);
uintmax_t		ft_get_uac(t_opt *opt, va_list args);
void			handle_cap_c(t_opt *opt, va_list args, int *printed);
void			handle_cap_s(t_opt *opt, va_list args, int *printed);
#endif
