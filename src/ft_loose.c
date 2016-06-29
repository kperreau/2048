/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 08:33:20 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/01 18:38:51 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	ft_display_gameover(void)
{
	int		key;

	key = 0;
	while (key != ENTER && key != ESCAPE && key != 343)
	{
		clear();
		bkgd(COLOR_PAIR(29));
		mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2 - 15, \
				"GAME OVER ! PRESS ENTER TO QUIT");
		refresh();
		key = getch();
	}
}

static int	ft_check_over(t_win *win)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if ((y > 0 && win->tab[y][x] == win->tab[y - 1][x]) ||
					(y < 3 && win->tab[y][x] == win->tab[y + 1][x]) ||
					(x > 0 && win->tab[y][x] == win->tab[y][x - 1]) ||
					(x < 3 && win->tab[y][x] == win->tab[y][x + 1]))
				return (0);
		}
	}
	return (1);
}

int			ft_isover(t_win *win)
{
	if (!ft_check_over(win))
		return (0);
	ft_display_gameover();
	return (-1);
}
