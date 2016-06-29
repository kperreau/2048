/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:39:36 by nverdonc          #+#    #+#             */
/*   Updated: 2015/03/01 21:47:06 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int		ft_calc_bin(int value)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (n < value)
	{
		n = 2 << (i - 1);
		if (n == value)
			return (i);
		++i;
	}
	return (0);
}

int				ft_color(t_win *win)
{
	int		color;

	color = ft_calc_bin(win->tab[win->c.y][win->c.x]) + 1;
	return (color);
}
