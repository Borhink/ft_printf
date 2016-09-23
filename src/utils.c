/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:01:06 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 04:07:15 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_nstr(const char *str, int n)
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

int		put_blank(int len, t_param *p)
{
	int		ret;

	if (p->lwth < 1 && p->flag[BLANK] && !p->neg
		&& valid_int(p->type) && !p->flag[PLUS])
	{
		ft_putchar(' ');
		return (1);
	}
	p->lwth -= len;
	ret = p->lwth > 0 ? p->lwth : 0;
	while (p->lwth-- > 0)
	{
		if (p->flag[ZERO] && p->flag[BLANK] && !p->flag[PLUS]
			&& !p->neg && p->type != 'p')
		{
			p->flag[BLANK] = 0;
			ft_putchar(' ');
		}
		else
			ft_putchar(p->flag[ZERO] ? '0' : ' ');
	}
	return (ret);
}

int		print_blankchar(char c, t_param *p)
{
	int		ret;

	if (!p->flag[MIN])
		ret = put_blank(1, p) + 1;
	ft_putchar(c);
	if (p->flag[MIN])
		ret = put_blank(1, p) + 1;
	return (ret);
}

char	*strjoin_n_free(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s2);
	return (str);
}
