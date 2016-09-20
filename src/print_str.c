/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:25:05 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/20 07:14:11 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_nstr(const char *str, int n)
{
	if (str && (int)(ft_strlen(str)) >= n)
	{
		write(1, str, n);
		return (n);
	}
	else
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
}

int		print_int(va_list *args)
{
	char	*str;
	int		ret;

	str = ft_itoa(va_arg(*args, int));
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int		print_uint(va_list *args)
{
	char	*str;
	int		ret;

	str = ft_uitoa(va_arg(*args, unsigned int));
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int		print_long(va_list *args)
{
	char	*str;
	int		ret;

	str = ft_ltoa(va_arg(*args, long));
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int		print_ulong(va_list *args)
{
	char	*str;
	int		ret;

	str = ft_ultoa(va_arg(*args, unsigned long));
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int		print_str(va_list *args)
{
	char	*str;
	int		ret;

	str = va_arg(*args, char *);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ret = ft_strlen(str);
	ft_putstr(str);
	return (ret);
}

int		print_ptr(va_list *args)
{
	char	*str;
	int		ret;

	str = ft_ltoa_base(va_arg(*args, long), 16, 0);
	ret = 2 + ft_strlen(str);
	ft_putstr("0x");
	ft_putstr(str);
	free(str);
	return (ret);
}

int		print_hexa_uint(va_list *args, int upper)
{
	char	*str;
	int		ret;

	str = ft_uitoa_base(va_arg(*args, int), 16, upper);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int		print_octal_int(va_list *args)
{
	char	*str;
	int		ret;

	str = ft_itoa_base(va_arg(*args, int), 8, 0);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int		print_octal_long(va_list *args)
{
	char	*str;
	int		ret;

	str = ft_ltoa_base(va_arg(*args, long), 8, 0);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int		print_char(va_list *args)
{
	ft_putchar(va_arg(*args, int));
	return (1);
}
