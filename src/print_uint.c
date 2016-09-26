/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 02:57:31 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/27 00:43:15 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_uint(va_list *args, t_param *p)
{
	char	*str;
	char	ret;

	get_wild_arg(args, p);
	if (p->lgt == 'l')
		str = ft_ultoa(va_arg(*args, unsigned long));
	else if (p->lgt == 'L')
		str = ft_ulltoa(va_arg(*args, unsigned long long));
	else if (p->lgt == 'h')
		str = ft_usitoa(va_arg(*args, unsigned int));
	else if (p->lgt == 'H')
		str = ft_uctoa(va_arg(*args, unsigned int));
	else if (p->lgt == 'j')
		str = ft_uimtoa(va_arg(*args, uintmax_t));
	else if (p->lgt == 'z')
		str = ft_stoa(va_arg(*args, size_t));
	else
		str = ft_uitoa(va_arg(*args, unsigned int));
	str = adjust_prec(str, p);
	if (!p->flag[MIN])
		ret = put_blank(ft_strlen(str), p) + ft_strlen(str);
	ft_putstr(str);
	if (p->flag[MIN])
		ret = put_blank(ft_strlen(str), p) + ft_strlen(str);
	free(str);
	return (ret);
}
