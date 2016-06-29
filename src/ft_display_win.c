/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:26:55 by nverdonc          #+#    #+#             */
/*   Updated: 2015/03/01 18:51:44 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		ft_display_winner(void)
{
	int		key;

	key = 0;
	while (key != ENTER && key != 343 && key != ESCAPE)
	{
		clear();
		mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2 - 24\
				, "YOU WIN ! PRESS ENTER TO CONTINUE OR ESCAPE TO EXIT");
		refresh();
		key = getch();
	}
	return ((key == ESCAPE) ? -1 : 0);
}
