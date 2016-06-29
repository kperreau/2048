/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:04:08 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/01 21:57:55 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void		ft_init_tab(t_win *win)
{
	int			*tab;
	int			i;
	t_coord		coord;

	tab = *win->tab;
	i = 0;
	while (i < 16)
	{
		tab[i] = 0;
		++i;
	}
	win->winner = 0;
	win->start = 0;
	coord = ft_rand_pos(win);
	win->tab[coord.y][coord.x] = 2;
	coord = ft_rand_pos(win);
	win->tab[coord.y][coord.x] = 2;
}

static void		ft_gen_color(void)
{
	init_color(12, 800, 800, 800);
	init_color(13, 800, 500, 800);
	init_color(14, 700, 400, 100);
	init_color(15, 200, 200, 600);
	init_color(16, 100, 500, 800);
	init_color(17, 200, 500, 800);
	init_color(18, 300, 400, 800);
	init_color(19, 100, 600, 800);
	init_color(20, 200, 500, 400);
	init_color(21, 500, 500, 800);
	init_color(22, 800, 500, 500);
	init_color(23, 1000, 0, 0);
	init_color(24, 1000, 500, 200);
	init_color(25, 800, 0, 800);
	init_color(26, 450, 450, 450);
	init_color(27, 0, 1000, 450);
	init_color(28, 0, 0, 1000);
}

int				ft_init(t_win *win)
{
	int		i;

	i = 0;
	initscr();
	start_color();
	ft_gen_color();
	init_pair(31, 26, 26);
	init_pair(30, COLOR_BLACK, COLOR_BLACK);
	init_pair(29, COLOR_WHITE, COLOR_BLACK);
	while (i++ < 17)
		init_pair(i, COLOR_BLACK, i + 11);
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	ft_init_tab(win);
	win->score = 4;
	return (0);
}
