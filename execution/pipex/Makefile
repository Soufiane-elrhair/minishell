# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 13:41:53 by selrhair          #+#    #+#              #
#    Updated: 2023/06/08 14:02:43 by selrhair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
NAME2 = pipex_bonus

SRCS = pipex.c childs.c childs_help.c utils_1.c utils_2.c utils_3.c

SRCSB = pipex_bonus.c G_N_L/get_next_line.c G_N_L/get_next_line_utils.c \
		help_functions_bonus.c ft_fork_bonus.c ft_heredoc_bonus.c \
		ft_work_bonus.c utils_1.c utils_2.c utils_3.c

OBJ = $(SRCS:.c=.o)

OBJB = $(SRCSB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME2)

$(NAME2): $(OBJB) 
	$(CC) $(CFLAGS) $(OBJB)  -o $(NAME2)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(PRINTF):
	cd printf && make

ss		:
		make re && make clean && clear

clean :
		rm -f $(OBJ) $(OBJB)

fclean : clean
		rm -f $(NAME) $(NAME2)

re : fclean all

ss : re clean