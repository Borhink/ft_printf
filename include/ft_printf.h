/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:40:42 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/26 10:14:37 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

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
	int		prec;
}				t_param;

int				ft_printf(const char *format, ...);
int				parse_arg(char **tmp, va_list *args);
int				print_arg(char type, va_list *args, t_param *p);

int				print_int(va_list *args, t_param *p);
int				print_uint(va_list *args, t_param *p);
int				print_char(va_list *args, t_param *p);
int				print_str(va_list *args, t_param *p);

int				print_ptr(va_list *args, t_param *p);
int				print_hexa_uint(va_list *args, int upper, t_param *p);
int				print_octal_uint(va_list *args, t_param *p);

char			*adjust_prec(char *str, t_param *p);
int				put_nstr(const char *str, int n);
int				print_blankchar(char c, t_param *p);
int				put_blank(int len, t_param *p);
char			*strjoin_n_free(char *s1, char *s2);

int				utf_strlen(wchar_t *wstr);
int				put_utfchar(wint_t c);
int				utfchar_len(wint_t c);
wchar_t			*utf_strsub(wchar_t *wstr, unsigned int start, size_t len);
int				print_utfstr(va_list *args, t_param *p);
int				print_utfchar(va_list *args, t_param *p);

int				valid_int(char c);
int				valid_arg(char c);
int				valid_length(char c);
int				valid_flag(char c);

#endif
