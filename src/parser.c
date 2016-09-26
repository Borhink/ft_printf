/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 04:57:37 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/27 00:41:28 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_precision(char **tmp, t_param *p)
{
	p->prec = -1;
	if (**tmp == '.')
	{
		(*tmp)++;
		p->prec = 0;
		while (ft_isdigit(**tmp) || **tmp == '*')
		{
			if (**tmp == '*')
				p->flag[PWILD] = 1;
			else
				p->prec = p->prec * 10 + (**tmp - '0');
			(*tmp)++;
		}
	}
	return (**tmp ? 1 : 0);
}

static int	parse_width_flag(char **tmp, t_param *p)
{
	int		i;

	p->lwth = 0;
	p->neg = 0;
	i = -1;
	while (++i < 7)
		p->flag[i] = 0;
	while (valid_flag(**tmp) || **tmp == '*')
	{
		if (**tmp == '*')
			p->flag[WILD] = 1;
		else
			p->flag[valid_flag(**tmp) - 1] = **tmp;
		(*tmp)++;
	}
	while (ft_isdigit(**tmp) || **tmp == '*')
	{
		if (**tmp == '*'/* && !p->lwth*/)
			p->flag[WILD] = 1;
		else// if (!p->flag[WILD])
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
	if (!parse_width_flag(tmp, &p) || !parse_length(tmp, &p)
	|| !parse_precision(tmp, &p))
		return (ret);
	ret = print_arg(**tmp, args, &p);
	(*tmp)++;
	return (ret);
}
