/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:09:41 by nverdonc          #+#    #+#             */
/*   Updated: 2015/03/01 20:29:13 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void		ft_up(t_win *win)
{
	int		y;
	int		x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (win->tab[y][x])
			{
				if (!win->d[win->best[x] - 1][x] && win->best[x] && \
					win->tab[y][x] == win->tab[win->best[x] - 1][x])
				{
					win->tab[--win->best[x]][x] *= 2;
					win->tab[y][x] = 0;
					win->d[win->best[x]][x] = 1;
				}
				else if (y && y != win->best[x])
				{
					win->tab[win->best[x]][x] = win->tab[y][x];
					win->tab[y][x] = 0;
				}
				++win->best[x];
			}
	}
}

static void		ft_down(t_win *win)
{
	int		y;
	int		x;

	y = 4;
	while (--y >= 0)
	{
		x = 4;
		while (--x >= 0)
			if (win->tab[y][x])
			{
				if (!win->d[win->best[x] + 1][x] && win->best[x] < 3 && \
					win->tab[y][x] == win->tab[win->best[x] + 1][x])
				{
					win->tab[++win->best[x]][x] *= 2;
					win->tab[y][x] = 0;
					win->d[win->best[x]][x] = 1;
				}
				else if (y != 3 && y != win->best[x])
				{
					win->tab[win->best[x]][x] = win->tab[y][x];
					win->tab[y][x] = 0;
				}
				--win->best[x];
			}
	}
}

static void		ft_left(t_win *win)
{
	int		y;
	int		x;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
			if (win->tab[y][x])
			{
				if (!win->d[y][win->best[y] - 1] && win->best[y] && \
					win->tab[y][x] == win->tab[y][win->best[y] - 1])
				{
					win->tab[y][--win->best[y]] *= 2;
					win->tab[y][x] = 0;
					win->d[y][win->best[y]] = 1;
				}
				else if (x && x != win->best[y])
				{
					win->tab[y][win->best[y]] = win->tab[y][x];
					win->tab[y][x] = 0;
				}
				++win->best[y];
			}
	}
}

static void		ft_right(t_win *win)
{
	int		y;
	int		x;

	x = 4;
	while (--x >= 0)
	{
		y = 4;
		while (--y >= 0)
			if (win->tab[y][x])
			{
				if (!win->d[y][win->best[y] + 1] && win->best[y] < 3 && \
					win->tab[y][x] == win->tab[y][win->best[y] + 1])
				{
					win->tab[y][++win->best[y]] *= 2;
					win->tab[y][x] = 0;
					win->d[y][win->best[y]] = 1;
				}
				else if (x != 3 && x != win->best[y])
				{
					win->tab[y][win->best[y]] = win->tab[y][x];
					win->tab[y][x] = 0;
				}
				--win->best[y];
			}
	}
}

int				ft_key_event(t_win *win, int key)
{
	if (key == UP || key == RIGHT || key == LEFT || key == DOWN)
	{
		ft_clear_tab(*win->d, 16, 0);
		if (key == DOWN || key == RIGHT)
			ft_clear_tab(win->best, 4, 3);
		else
			ft_clear_tab(win->best, 4, 0);
		ft_cpy_tab(win);
		if (key == UP)
			ft_up(win);
		else if (key == DOWN)
			ft_down(win);
		else if (key == LEFT)
			ft_left(win);
		else if (key == RIGHT)
			ft_right(win);
		if (ft_add_case(win) == -1)
			return (-1);
		ft_score(win);
	}
	return (0);
}
