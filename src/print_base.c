/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:25:32 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/26 03:24:01 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_arg(va_list *args, t_param *p, int base, int upper)
{
	if (p->lgt == 'l')
		return (ft_ultoa_base(va_arg(*args, unsigned long), base, upper));
	else if (p->lgt == 'L')
		return (ft_ulltoa_base(va_arg(*args, unsigned long long), base, upper));
	else if (p->lgt == 'h')
		return (ft_usitoa_base(va_arg(*args, unsigned int), base, upper));
	else if (p->lgt == 'H')
		return (ft_uctoa_base(va_arg(*args, unsigned int), base, upper));
	else if (p->lgt == 'j')
		return (ft_uimtoa_base(va_arg(*args, uintmax_t), base, upper));
	else if (p->lgt == 'z')
		return (ft_stoa_base(va_arg(*args, size_t), base, upper));
	else
		return (ft_uitoa_base(va_arg(*args, unsigned int), base, upper));
}

int			print_ptr(va_list *args, t_param *p)
{
	char	*str;
	int		ret;

	str = ft_ltoa_base(va_arg(*args, long), 16, 0);
	str = adjust_prec(str, p);
	str = strjoin_n_free("0x", str);
	if (!p->flag[MIN] && !p->flag[ZERO])
		ret = put_blank(ft_strlen(str), p) + ft_strlen(str);
	ft_putstr(str);
	if (p->flag[MIN] || p->flag[ZERO])
		ret = put_blank(ft_strlen(str), p) + ft_strlen(str);
	free(str);
	return (ret);
}

int			print_hexa_uint(va_list *args, int upper, t_param *p)
{
	char	*str;
	int		ret;
	int		zero;

	ret = 0;
	str = get_arg(args, p, 16, upper);
	zero = (*str == '0' ? 1 : 0);
	str = adjust_prec(str, p);
	if (!p->flag[MIN])
		ret += put_blank(ft_strlen(str), p) + ft_strlen(str);
	if (p->flag[SHARP] && !zero)
		ret += (upper ? ft_putstr("0X") : ft_putstr("0x"));
	ft_putstr(str);
	if (p->flag[MIN])
		ret += put_blank(ft_strlen(str), p) + ft_strlen(str);
	free(str);
	return (ret);
}

int			print_octal_uint(va_list *args, t_param *p)
{
	char	*str;
	int		ret;
	int		zero;

	ret = 0;
	str = get_arg(args, p, 8, 0);
	zero = (*str == '0' ? 1 : 0);
	str = adjust_prec(str, p);
	if (!p->flag[MIN])
		ret += put_blank(ft_strlen(str), p) + ft_strlen(str);
	if (p->flag[SHARP] && (!zero || !p->prec))
		ret += ft_putchar('0');
	ft_putstr(str);
	if (p->flag[MIN])
		ret += put_blank(ft_strlen(str), p) + ft_strlen(str);
	free(str);
	return (ret);
}
