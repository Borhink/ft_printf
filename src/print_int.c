/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 02:39:37 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 04:49:15 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_int(va_list *args, t_param *p)
{
	char	*str;
	char	ret;

	ret = 0;
	if (p->lgt == 'l')
		str = ft_ltoa(va_arg(*args, long));
	else if (p->lgt == 'L')
		str = ft_lltoa(va_arg(*args, long long));
	else if (p->lgt == 'h')
		str = ft_sitoa(va_arg(*args, int));
	else if (p->lgt == 'H')
		str = ft_sctoa(va_arg(*args, int));
	else if (p->lgt == 'j')
		str = ft_imtoa(va_arg(*args, intmax_t));
	else if (p->lgt == 'z')
		str = ft_stoa(va_arg(*args, size_t));
	else
		str = ft_itoa(va_arg(*args, int));
	if (p->flag[PLUS] && *str != '-')
		str = strjoin_n_free("+", str);
	p->neg = (*str == '-' ? 1 : 0);
	if (*str == '0' && p->flag[MIN])
		p->flag[ZERO] = 0;
	if ((p->neg || p->flag[PLUS]) && p->flag[ZERO])
		ft_putchar(*str);
	if (!p->flag[MIN])
		ret += put_blank(ft_strlen(str), p) + ft_strlen(str);
	(p->neg || p->flag[PLUS]) && p->flag[ZERO] ? ft_putstr(str + 1) : ft_putstr(str);
	if (p->flag[MIN])
		ret += put_blank(ft_strlen(str), p) + ft_strlen(str);
	free(str);
	return (ret);
}
