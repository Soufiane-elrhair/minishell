# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:14:19 by selrhair          #+#    #+#              #
#    Updated: 2023/05/11 16:18:57 by selrhair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

CC		= cc
# HEADER	= -I./inc
# CFLAGS	=  -Wall -Wextra -Werror
RM		= rm -rf

# colors
NONE	= \033[0m
YALLOW	= \033[1;93m
Green	= \033[1;32m

# src files
SRCS	= main.c


# SRCS	= $(addprefix ./src/, $(SRC)) main.c

# obj files
OBJS	= $(SRCS:.c=.o)

all : $(NAME)

%.o:%.c
	@echo "$(Green)Compaling file $<$(NONE)"
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS) $(LIBFT)
	@echo  "$(YALLOW)\n[$@]$(NONE)"
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean :
	@echo "$(Green)Cleaning obj files....$(NONE)"
	$(RM) $(OBJS)

fclean : clean
	@echo "$(Green)Clean all ....$(NONE)"
	$(RM) $(NAME)

re: fclean all