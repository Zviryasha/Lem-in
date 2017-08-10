# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opanchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/06 12:39:22 by opanchen          #+#    #+#              #
#    Updated: 2017/08/09 09:39:50 by opanchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc

HEAD = lem_in.h get_next_line.h 

HEAD_GCH = $(HEAD:.h=.h.gch)

FLAGS = -Wall -Wextra -Werror

SRC = lem_in_main.c \
	  get_next_line.c \
	  pars.c \
	  start.c \
	  chrm.c \
	  my_atoi.c \
	  wtf.c \
	  add_rm.c \
	  add_start.c \
	  add_conect.c \
	  check_doubl.c \
	  solve.c \
	  printing.c \
	  ck_empty.c  \
	  main.c \
	  lem_main1.c \
	  solve1.c \
	  add_conect_2.c \
	  color.c

SRO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRO)
			make -C libft
			$(CC) $(FLAGS) -c $(SRC) $(HEAD)
			$(CC) $(FLAGS) -o $(NAME) $(SRO) libft/libft.a


clean:
			make clean -C ./libft
			@rm -f $(SRO) $(HEAD_GCH)

fclean:
			make fclean -C ./libft
			@make clean
			@rm -f $(NAME)

re:
	make fclean
	make all
