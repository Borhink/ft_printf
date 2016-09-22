/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 18:07:07 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 00:16:24 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		valid_arg(char c)
{
	return (c == 'd' || c == 'D' || c == 'i' || c == 's' || c == 'S' || c == 'p'
	|| c == 'o' || c == 'O' || c == 'x' || c == 'X' || c == 'u' || c == 'U'
	|| c == 'c' || c == 'C');
}

int		valid_length(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z');
}

int		valid_flag(char c)
{
	if (c == '#')
		return (SHARP + 1);
	if (c == '0')
		return (ZERO + 1);
	if (c == '-')
		return (MIN + 1);
	if (c == '+')
		return (PLUS + 1);
	if (c == ' ')
		return (BLANK + 1);
	return (0);
}
