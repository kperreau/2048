/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 04:58:42 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/01 20:39:32 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void		ft_border_x(WINDOW *win, int y, int x)
{
	int		i;

	i = 1;
	while (i < x)
	{
		mvwprintw(win, y, i, " ");
		++i;
	}
}

static void		ft_border_y(WINDOW *win, int y, int x)
{
	int		i;

	i = 1;
	while (i < y)
	{
		mvwprintw(win, i, x, " ");
		++i;
	}
}

static void		ft_border(WINDOW *win, int x, int y, int index)
{
	int		px;
	int		py;

	px = index % 4;
	py = index / 4;
	mvwprintw(win, 0, 0, " ");
	ft_border_x(win, 0, x);
	ft_border_y(win, y, 0);
	if (py == 3)
	{
		mvwprintw(win, y - 1, x - 1, " ");
		ft_border_x(win, y - 1, x - 1);
	}
	if (px == 3)
	{
		mvwprintw(win, 0, x - 1, " ");
		ft_border_y(win, y, x - 1);
	}
	if (px == 3 && py == 3)
		mvwprintw(win, y - 1, x - 1, " ");
}

static void		ft_calc(t_win *win)
{
	int		n;

	n = win->tab[win->c.y][win->c.x];
	win->win[win->c.y][win->c.x] = newwin(win->height, win->width, \
			win->c.y * win->height, win->c.x * win->width);
	wbkgd(win->win[win->c.y][win->c.x], COLOR_PAIR(ft_color(win)));
	wattron(win->win[win->c.y][win->c.x], COLOR_PAIR(31));
	ft_border(win->win[win->c.y][win->c.x], win->width, win->height, \
			win->c.y * 4 + win->c.x);
	wattroff(win->win[win->c.y][win->c.x], COLOR_PAIR(30));
	if (n)
		mvwprintw(win->win[win->c.y][win->c.x], win->height / 2, \
			(win->width - (ft_nbrlen(n) / 2)) / 2, "%d", n);
	wrefresh(win->win[win->c.y][win->c.x]);
}

int				ft_init_win(t_win *win)
{
	win->c.y = 0;
	win->c.x = 0;
	win->height = win->max.y / 4;
	win->width = win->max.x / 4;
	while (win->c.y < 4)
	{
		win->c.x = 0;
		while (win->c.x < 4)
		{
			ft_calc(win);
			++win->c.x;
		}
		++win->c.y;
	}
	return (0);
}
