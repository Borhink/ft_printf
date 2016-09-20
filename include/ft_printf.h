/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:40:42 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/20 23:18:10 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

#include <stdio.h>

typedef struct	s_param
{
	char	lgt;
}				t_param;

int		ft_printf(const char *format, ...);
int		print_nstr(const char *str, int n);
int		print_int(va_list *args, t_param *p);
int		print_long(va_list *args);
int		print_uint(va_list *args, t_param *p);
int		print_ulong(va_list *args);
int		print_char(va_list *args, t_param *p);
int		print_str(va_list *args, t_param *p);
int		print_ptr(va_list *args);
int		print_hexa_uint(va_list *args, int upper, t_param *p);
int		print_octal_uint(va_list *args, t_param *p);
int		print_octal_ulong(va_list *args);
int		utf_strlen(wchar_t *wstr);
int		put_utfchar(wint_t c);
int		print_utfstr(va_list *args);
int		print_utfchar(va_list *args);

int		valid_arg(char c);
int		valid_length(char c);
int		valid_flag(char c);

#endif
