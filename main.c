/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:03:25 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/27 13:09:02 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		i;
	int		j;

	ft_printf("{:blue}Test{:eoc} de couleur : {:red}%s{:eoc}\n", "COLOR");
	ft_printf("Je%n suis %d une %nphrase\n", &i, -218, &j);
	ft_printf("%d, %d\n", i, j);
	ft_printf("print base : %d -> %b\n", 42, 4, 42);
	i = ft_printf("print file in grey:\n{:grey}%r{:eoc}", "src/color.c");
	ft_printf("%d\n", i);
	return (0);
}
