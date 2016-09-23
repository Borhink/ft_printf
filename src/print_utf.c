/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 02:16:30 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 04:53:50 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_utfstr(va_list *args, t_param *p)
{
	wchar_t	*wstr;
	int		ret;
	int		i;

	wstr = va_arg(*args, wchar_t *);
	ret = 0;
	if (!wstr)
		return (ft_putstr("(null)"));
	i = 0;
	if (!p->flag[MIN])
		ret += put_blank(utf_strlen(wstr), p);
	while (wstr[i])
		ret += put_utfchar(wstr[i++]);
	if (p->flag[MIN])
		ret += put_blank(utf_strlen(wstr), p);
	return (ret);
}

int		print_utfchar(va_list *args, t_param *p)
{
	int		ret;
	wint_t	wc;

	wc = va_arg(*args, wint_t);
	ret = 0;
	if (!p->flag[MIN])
		ret += put_blank(utfchar_len(wc), p);
	ret += put_utfchar(wc);
	if (p->flag[MIN])
		ret += put_blank(utfchar_len(wc), p);
	return (ret);
}
