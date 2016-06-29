/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:49:49 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/01 11:29:18 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int			ft_count_cases(int *tab)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (i < 16)
	{
		if (!tab[i])
			++n;
		++i;
	}
	return (n);
}

static void			ft_tab_cases(int *cases, int *tab)
{
	int		i;
	int		index;

	ft_clear_tab(cases, 16, 0);
	i = 0;
	index = 0;
	while (i < 16)
	{
		if (!tab[i])
		{
			cases[index] = i;
			++index;
		}
		++i;
	}
}

t_coord				ft_rand_pos(t_win *win)
{
	t_coord		coord;
	int			randi;
	int			cases[16];
	int			n;

	n = ft_count_cases(*win->tab);
	coord.x = -1;
	coord.y = -1;
	if (n)
	{
		ft_tab_cases(cases, *win->tab);
		srand(time(NULL));
		randi = (rand() % n);
		coord.x = cases[randi] % 4;
		coord.y = cases[randi] / 4;
	}
	return (coord);
}
