/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 04:57:37 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 05:00:24 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_width_flag(char **tmp, t_param *p)
{
	int		i;

	p->lwth = 0;
	p->neg = 0;
	i = -1;
	while (++i < 5)
		p->flag[i] = 0;
	while (valid_flag(**tmp))
	{
		p->flag[valid_flag(**tmp) - 1] = **tmp;
		(*tmp)++;
	}
	while (ft_isdigit(**tmp))
	{
		p->lwth = p->lwth * 10 + (**tmp - '0');
		(*tmp)++;
	}
	return (**tmp ? 1 : 0);
}

static int	parse_length(char **tmp, t_param *p)
{
	p->lgt = 0;
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

int			parse_arg(char **tmp, va_list *args)
{
	int		ret;
	t_param	p;

	ret = 0;
	(*tmp)++;
	if (!parse_width_flag(tmp, &p) || !parse_length(tmp, &p))
		return (ret);
	ret = print_arg(**tmp, args, &p);
	(*tmp)++;
	return (ret);
}
