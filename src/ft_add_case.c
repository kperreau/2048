/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:01:56 by nverdonc          #+#    #+#             */
/*   Updated: 2015/03/01 18:48:07 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		ft_add_case(t_win *win)
{
	t_coord		coord;

	srand(time(NULL));
	coord = ft_rand_pos(win);
	if (!win->winner && ft_iswin(win))
		return (ft_display_winner());
	else if (coord.x != -1)
	{
		if (ft_cmp_tab(win))
			win->tab[coord.y][coord.x] = ((rand() % 10) > 8) ? 4 : 2;
	}
	else
		return (ft_isover(win));
	return (0);
}
