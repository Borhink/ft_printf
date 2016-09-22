/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:40:42 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/22 21:19:44 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

#include <stdio.h>

# define MIN 0
# define PLUS 1
# define BLANK 2
# define SHARP 3
# define ZERO 4

typedef struct	s_param
{
	int		type;
	char	lgt;
	char	flag[5];
	int		lwth;
	int		neg;
}				t_param;

int		ft_printf(const char *format, ...);
int		print_nstr(const char *str, int n);
int		print_int(va_list *args, t_param *p);
int		print_long(va_list *args, t_param *p);
int		print_uint(va_list *args, t_param *p);
int		print_ulong(va_list *args, t_param *p);
int		print_char(va_list *args, t_param *p);
int		print_str(va_list *args, t_param *p);
int		print_ptr(va_list *args, t_param *p);
int		print_hexa_uint(va_list *args, int upper, t_param *p);
int		print_octal_uint(va_list *args, t_param *p);
int		print_octal_ulong(va_list *args, t_param *p);
int		utf_strlen(wchar_t *wstr);
int		put_utfchar(wint_t c);
int		print_utfstr(va_list *args, t_param *p);
int		print_utfchar(va_list *args, t_param *p);
int		print_blankchar(char c, t_param *p);
int		put_blank(int len, t_param *p);

int		valid_arg(char c);
int		valid_length(char c);
int		valid_flag(char c);

#endif
