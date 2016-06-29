/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:53:30 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/01 23:06:30 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		ft_menu(t_win *win)
{
	int		key;

	key = 0;
	while (key != ESCAPE && key != ENTER && key != 343)
	{
		if (key == UP || key == DOWN)
			win->start = (key == UP) ? 0 : 1;
		clear();
		attron(COLOR_PAIR(29));
		mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2 - 3, \
			"Ready ?");
		if (!win->start)
			attron(COLOR_PAIR(5));
		mvprintw(getmaxy(stdscr) / 2 + 1, getmaxx(stdscr) / 2 - 3, "Yes");
		attron(COLOR_PAIR(29));
		if (win->start)
			attron(COLOR_PAIR(5));
		mvprintw(getmaxy(stdscr) / 2 + 2, getmaxx(stdscr) / 2 - 3, "No");
		refresh();
		key = getch();
	}
	return ((key == ESCAPE || key == 110 || win->start) ? ESCAPE : 0);
}
