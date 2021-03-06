/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:29:18 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/01 20:30:52 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void		ft_score(t_win *win)
{
	int		x;
	int		y;

	win->score = 0;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			win->score += win->tab[y][x];
		}
	}
}
