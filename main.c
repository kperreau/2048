/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:48:53 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/01 21:06:34 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int		ft_boucle(t_win *win)
{
	clear();
	wrefresh(stdscr);
	getmaxyx(stdscr, win->max.y, win->max.x);
	--win->max.y;
	if (win->max.y > 12 && win->max.x > 30)
	{
		ft_init_win(win);
		mvprintw(win->max.y, 0, "Score: %d", win->score);
	}
	else
	{
		clear();
		printw("Please rezise window.");
		wrefresh(stdscr);
		ft_del_win(win);
		getch();
		return (-1);
	}
	return (0);
}

int				main(void)
{
	int			key;
	t_win		win;

	if ((WIN_VALUE & (~WIN_VALUE + 1)) == WIN_VALUE && WIN_VALUE > 1)
	{
		ft_init(&win);
		key = 0;
		key = ft_menu(&win);
		while (key != ESCAPE)
		{
			if (ft_boucle(&win) != -1)
			{
				key = getch();
				if (ft_key_event(&win, key) == -1)
					break ;
			}
			ft_del_win(&win);
		}
		endwin();
	}
	else
		ft_putendl_fd("Bad number for win", 2);
	return (0);
}
