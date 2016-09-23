/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:26:32 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 08:36:01 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(const char *format, va_list *args, int ret)
{
	char	*tmp;
	int		i;
	int		len;

	if (!(*format))
		return (ret);
	if ((tmp = ft_strchr(format, '%')))
	{
		i = tmp - format;
		len = put_nstr(format, i);
		len += parse_arg(&tmp, args);
		return (print_format(tmp, args, ret + len));
	}
	ft_putstr(format);
	ret += ft_strlen(format);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list args;
	int		ret;

	va_start(args, format);
	ret = print_format(format, &args, 0);
	va_end(args);
	return (ret);
}
