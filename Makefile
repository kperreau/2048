# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 14:10:51 by kperreau          #+#    #+#              #
#    Updated: 2015/03/01 20:52:09 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

# Dir vars

SRCDIR = src

INCLUDESDIR = includes

LIBDIR = libft

# Files vars

MAIN = main.c

CFILES = ft_init.c ft_del_win.c ft_key_event.c ft_funcs.c ft_color.c \
		ft_gen_win.c ft_utils.c ft_winner.c ft_tab.c ft_clear_tab.c \
		ft_loose.c ft_add_case.c ft_display_win.c ft_score.c ft_menu.c

SRC = $(patsubst %, $(SRCDIR)/%, $(CFILES))

OBJ = $(SRC:.c=.o)

HFILES = rush.h

HEADERS = $(patsubst %, $(INCLUDESDIR)/%, $(HFILES))

# COMPILATION

ERRORFLAGS = -Wall -Werror -Wextra -W -O3
# ERRORFLAGS = -O3

INCLUDEFLAGS = -I $(INCLUDESDIR)/ -I $(LIBDIR)/includes/ -lcurses

LIBFLAGS = -L $(LIBDIR)/ -lft

FLAGS = $(ERRORFLAGS) $(INCLUDEFLAGS)

CC = gcc

# Git vars

TOGIT =	$(SRC) \
		$(HEADERS) \
		$(MAIN) \
		Makefile \
		auteur \
		$(LIBDIR)

# Rules

all: $(NAME)

$(NAME): $(OBJ)
			@make -j -C $(LIBDIR)/
			@$(CC) $(FLAGS) $(OBJ) $(MAIN) $(LIBFLAGS) -o $(NAME)

re: fclean all

clean:
			@rm -f $(OBJ)
			@make -C $(LIBDIR)/ clean

fclean: clean
			@rm -f $(NAME)
			@make -j -C $(LIBDIR)/ fclean

relib:
		@make -j -C $(LIBDIR)/ re

%.o: %.c
			@$(CC) -o $@ -c $< $(FLAGS)

git:
		git add $(TOGIT)
		git commit -m 'auto update'
		git push
