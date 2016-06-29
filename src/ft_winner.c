/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 08:33:20 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/01 11:29:03 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int					ft_iswin(t_win *win)
{
	t_winner	winner;
	int			x;
	int			y;

	winner = WIN_VALUE;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if ((size_t)win->tab[y][x] == winner)
			{
				win->winner = 1;
				return (1);
			}
		}
	}
	return (0);
}
