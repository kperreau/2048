/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 06:57:38 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/01 20:28:39 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void		ft_cpy_tab(t_win *win)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			win->cpy[y][x] = win->tab[y][x];
			++x;
		}
		++y;
	}
}
