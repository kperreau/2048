/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:31:29 by nverdonc          #+#    #+#             */
/*   Updated: 2015/03/01 21:03:37 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# define ESCAPE 27
# define ENTER 10
# define UP 259
# define DOWN 258
# define LEFT 260
# define RIGHT 261
# include <curses.h>
# include <libft.h>
# include <time.h>

typedef enum	e_winner
{
	WIN_VALUE = 2048
}				t_winner;

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_win
{
	t_coord		max;
	WINDOW		*win[4][4];
	int			tab[4][4];
	int			cpy[4][4];
	int			d[4][4];
	int			best[4];
	t_coord		c;
	int			height;
	int			width;
	int			winner;
	int			defeat;
	int			score;
	int			start;
}				t_win;

/*
**INIT
*/
int				ft_init(t_win *win);
int				ft_init_win(t_win *win);

/*
**FUNCTIONS
*/
void			ft_del_win(t_win *win);
int				ft_key_event(t_win *win, int key);
void			ft_clear_tab(int *tab, int n, int value);
void			ft_cpy_tab(t_win *win);
int				ft_cmp_tab(t_win *win);
void			ft_merge(t_win *win, int x, int y);
int				ft_add_case(t_win *win);
int				ft_iswin(t_win *win);
int				ft_isover(t_win *win);
t_coord			ft_rand_pos(t_win *win);
int				ft_display_winner(void);
int				ft_color(t_win *win);
void			ft_score(t_win *win);
int				ft_menu(t_win *win);

#endif
