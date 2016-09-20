/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 02:16:30 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/20 07:23:07 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_utfchar(wint_t c)
{
	if (c >= 1114112)
		return (0);
	if (c < 128)
	{
		ft_putchar(c);
		return (1);
	}
	else if (c < 2048)
	{
		ft_putchar(192 | (c >> 6));
		ft_putchar(128 | (c & 63));
		return (2);
	}
	else if (c < 65536)
	{
		ft_putchar(224 | (c >> 12));
		ft_putchar(128 | ((c >> 6) & 63));
		ft_putchar(128 | (c & 63));
		return (3);
	}
	ft_putchar(240 | (c >> 18));
	ft_putchar(128 | ((c >> 12) & 63));
	ft_putchar(128 | ((c >> 6) & 63));
	ft_putchar(128 | (c & 63));
	return (4);
}

int		utf_strlen(wchar_t *wstr)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (wstr[i])
	{
		if (wstr[i] < 128)
			len++;
		else if (wstr[i] < 2048)
			len += 2;
		else if (wstr[i] < 65536)
			len += 3;
		else if (wstr[i] < 1114112)
			len += 4;
		i++;
	}
	return (len);
}

int		print_utfstr(va_list *args)
{
	wchar_t	*wstr;
	int		ret;
	int		i;

	wstr = va_arg(*args, wchar_t *);
	if (!wstr)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	ret = 0;
	while (wstr[i])
	{
		ret += put_utfchar(wstr[i]);
		i++;
	}
	return (ret);
}

int		print_utfchar(va_list *args)
{
	int		ret;

	ret = put_utfchar(va_arg(*args, wint_t));
	return (ret);
}
