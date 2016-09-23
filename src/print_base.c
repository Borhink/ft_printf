/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:25:32 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 04:43:11 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_ptr(va_list *args, t_param *p)
{
	char	*str;
	int		ret;

	str = ft_ltoa_base(va_arg(*args, long), 16, 0);
	str = strjoin_n_free("0x", str);
	if (!p->flag[MIN] && !p->flag[ZERO])
		ret = put_blank(ft_strlen(str), p) + ft_strlen(str);
	ft_putstr(str);
	if (p->flag[MIN] || p->flag[ZERO])
		ret = put_blank(ft_strlen(str), p) + ft_strlen(str);
	free(str);
	return (ret);
}

int		print_hexa_uint(va_list *args, int upper, t_param *p)
{
	char	*str;
	int		ret;

	ret = 0;
	if (p->lgt == 'l')
		str = ft_ultoa_base(va_arg(*args, unsigned long), 16, upper);
	else if (p->lgt == 'L')
		str = ft_ulltoa_base(va_arg(*args, unsigned long long), 16, upper);
	else if (p->lgt == 'h')
		str = ft_usitoa_base(va_arg(*args, unsigned int), 16, upper);
	else if (p->lgt == 'H')
		str = ft_uctoa_base(va_arg(*args, unsigned int), 16, upper);
	else if (p->lgt == 'j')
		str = ft_uimtoa_base(va_arg(*args, uintmax_t), 16, upper);
	else if (p->lgt == 'z')
		str = ft_stoa_base(va_arg(*args, size_t), 16, upper);
	else
		str = ft_uitoa_base(va_arg(*args, unsigned int), 16, upper);
	if (!p->flag[MIN])
		ret += put_blank(ft_strlen(str), p) + ft_strlen(str);
	if (p->flag[SHARP] && *str != '0')
		ret += (upper ? ft_putstr("0X") : ft_putstr("0x"));
	ft_putstr(str);
	if (p->flag[MIN])
		ret += put_blank(ft_strlen(str), p) + ft_strlen(str);
	free(str);
	return (ret);
}

int		print_octal_uint(va_list *args, t_param *p)
{
	char	*str;
	int		ret;

	ret = 0;
	if (p->lgt == 'l')
		str = ft_ultoa_base(va_arg(*args, unsigned long), 8, 0);
	else if (p->lgt == 'L')
		str = ft_ulltoa_base(va_arg(*args, unsigned long long), 8, 0);
	else if (p->lgt == 'h')
		str = ft_usitoa_base(va_arg(*args, unsigned int), 8, 0);
	else if (p->lgt == 'H')
		str = ft_uctoa_base(va_arg(*args, unsigned int), 8, 0);
	else if (p->lgt == 'j')
		str = ft_uimtoa_base(va_arg(*args, uintmax_t), 8, 0);
	else if (p->lgt == 'z')
		str = ft_stoa_base(va_arg(*args, size_t), 8, 0);
	else
		str = ft_uitoa_base(va_arg(*args, unsigned int), 8, 0);
	if (!p->flag[MIN])
		ret += put_blank(ft_strlen(str), p) + ft_strlen(str);
	if (p->flag[SHARP] && *str != '0')
		ret += ft_putchar('0');
	ft_putstr(str);
	if (p->flag[MIN])
		ret += put_blank(ft_strlen(str), p) + ft_strlen(str);
	free(str);
	return (ret);
}
