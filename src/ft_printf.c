/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:26:32 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/20 23:18:11 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg(char type, va_list *args, t_param *p)
{
	if (type == 'd' || type == 'i')
		return (print_int(args, p));
	if (type == 'D')
		return (print_long(args));
	if (type == 's')
		return (print_str(args, p));
	if (type == 'S')
		return (print_utfstr(args));
	if (type == 'p')
		return (print_ptr(args));
	if (type == 'o')
		return (print_octal_uint(args, p));
	if (type == 'O')
		return (print_octal_ulong(args));
	if (type == 'x')
		return (print_hexa_uint(args, 0, p));
	if (type == 'X')
		return (print_hexa_uint(args, 1, p));
	if (type == 'u')
		return (print_uint(args, p));
	if (type == 'U')
		return (print_ulong(args));
	if (type == 'c')
		return (print_char(args, p));
	if (type == 'C')
		return (print_utfchar(args));
	ft_putchar(type);
	return (1);
}

static void	skip_spaces(char **tmp)
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
}

static int	parse_length(char **tmp, t_param *p)
{
	p->lgt = 0;
	// if ((valid_flag(**tmp) || ft_isdigit(**tmp) || **tmp == '.'
	// || **tmp != '\0') && !valid_length(**tmp) && !valid_arg(**tmp))
	// 	(*tmp)++;
	if (valid_length(**tmp))
	{
		p->lgt = **tmp;
		(*tmp)++;
		if (**tmp == p->lgt)
		{
			p->lgt = ft_toupper(p->lgt);
			(*tmp)++;
		}
	}
	return (**tmp ? 1 : 0);
}

static int	parse_arg(char **tmp, va_list *args)
{
	int		ret;
	t_param	p;

	ret = 0;
	skip_spaces(tmp);
	if (!parse_length(tmp, &p))
		return (ret);
	ret = print_arg(**tmp, args, &p);
	(*tmp)++;
	return (ret);
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
		len = print_nstr(format, i);
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
