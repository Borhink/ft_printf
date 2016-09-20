/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:26:32 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/20 07:15:55 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg(char type, va_list *args)
{
	if (type == 'd' || type == 'i')
		return (print_int(args));
	if (type == 'D')
		return (print_long(args));
	if (type == 's')
		return (print_str(args));
	if (type == 'S')
		return (print_utfstr(args));
	if (type == 'p')
		return (print_ptr(args));
	if (type == 'o')
		return (print_octal_int(args));
	if (type == 'O')
		return (print_octal_long(args));
	if (type == 'x')
		return (print_hexa_uint(args, 0));
	if (type == 'X')
		return (print_hexa_uint(args, 1));
	if (type == 'u')
		return (print_uint(args));
	if (type == 'U')
		return (print_ulong(args));
	if (type == 'c')
		return (print_char(args));
	if (type == 'C')
		return (print_utfchar(args));
	ft_putchar(type);
	return (1);
}

static int	parse_arg(char **tmp, va_list *args)
{
	int		ret;

	ret = print_arg(**tmp, args);
	(*tmp)++;
	return (ret);
}

// static int	valid_arg(char type)
// {
// 	return (type == 'd' || type == 's' || type == 'p' || type == 's');
// }

static int	skip_spaces(char **tmp)
{
	(*tmp)++;
	// if (**tmp == ' ')
	// {
		while (**tmp == ' ')
			(*tmp)++;
	// 	if (valid_arg(**tmp))
	// 	{
	// 		ft_putchar(' ');
	// 		return (1);
	// 	}
	// }
	return (0);
}

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
		if (DEBUG) printf("\nprintnstr(format, i) %d : %s\n", ret, tmp);
		len = print_nstr(format, i);
		if (DEBUG) printf("\nskip_spaces(&tmp) %d : %s\n", ret + len, tmp);
		len += skip_spaces(&tmp);
		if (DEBUG) printf("\nparse_arg(&tmp, args) %d : %s\n", ret + len, tmp);
		if (*tmp)
			len += parse_arg(&tmp, args);
		return (print_format(tmp, args, ret + len));
	}
	ft_putstr(format);
	ret += ft_strlen(format);
	if (DEBUG) printf("\nft_putstr(format) %d : %s\n", ret, format);
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
