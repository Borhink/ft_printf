/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:25:05 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/21 23:31:35 by qhonore          ###   ########.fr       */
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

int		put_wthstr(char *str, t_param *p)
{
	int		ret;
	int		len;

	len = ft_strlen(str);
	p->lwth -= len;
	ret = p->lwth > 0 ? p->lwth + len : len;
	while (p->lwth-- > 0)
	{
		if (p->flag[ZERO] && p->flag[BLANK])
		{
			p->flag[BLANK] = 0;
			ft_putchar(' ');
		}
		else
			ft_putchar(p->flag[ZERO] ? '0' : ' ');
	}
	ft_putstr(str);
	return (ret);
}

int		print_int(va_list *args, t_param *p)
{
	char	*str;
	char	ret;

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
	ret = put_wthstr(str, p);
	free(str);
	return (ret);
}

int		print_uint(va_list *args, t_param *p)
{
	char	*str;
	char	ret;

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
	ret = put_wthstr(str, p);
	free(str);
	return (ret);
}

int		print_long(va_list *args, t_param *p)
{
	char	*str;
	char	ret;

	str = ft_ltoa(va_arg(*args, long));
	ret = put_wthstr(str, p);
	free(str);
	return (ret);
}

int		print_ulong(va_list *args, t_param *p)
{
	char	*str;
	char	ret;

	str = ft_ultoa(va_arg(*args, unsigned long));
	ret = put_wthstr(str, p);
	free(str);
	return (ret);
}

int		print_str(va_list *args, t_param *p)
{
	char	*str;
	int		ret;

	if (p->lgt == 'l')
		return (print_utfstr(args));
	str = va_arg(*args, char *);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ret = put_wthstr(str, p);
	return (ret);
}

int		print_ptr(va_list *args, t_param *p)
{
	char	*str;
	char	*tmp;
	int		ret;

	tmp = ft_ltoa_base(va_arg(*args, long), 16, 0);
	str = ft_strjoin("0x", tmp);
	free(tmp);
	ret = put_wthstr(str, p);
	free(str);
	return (ret);
}

int		print_hexa_uint(va_list *args, int upper, t_param *p)
{
	char	*str;
	int		ret;

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
	ret = put_wthstr(str, p);
	free(str);
	return (ret);
}

int		print_octal_uint(va_list *args, t_param *p)
{
	char	*str;
	int		ret;

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
	ret = put_wthstr(str, p);
	free(str);
	return (ret);
}

int		print_octal_ulong(va_list *args, t_param *p)
{
	char	*str;
	int		ret;

	str = ft_ultoa_base(va_arg(*args, unsigned long), 8, 0);
	ret = put_wthstr(str, p);
	free(str);
	return (ret);
}

int		print_char(va_list *args, t_param *p)
{
	int		ret;

	if (p->lgt == 'l')
		return (print_utfchar(args));
	p->lwth -= 1;
	ret = p->lwth > 0 ? p->lwth + 1 : 1;
	while (p->lwth-- > 0)
	{
		if (p->flag[ZERO] && p->flag[BLANK])
		{
			p->flag[BLANK] = 0;
			ft_putchar(' ');
		}
		else
			ft_putchar(p->flag[ZERO] ? '0' : ' ');
	}
	ft_putchar(va_arg(*args, int));
	return (ret);
}
