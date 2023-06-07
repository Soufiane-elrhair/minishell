# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selrhair <selrhair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:14:19 by selrhair          #+#    #+#              #
#    Updated: 2023/06/07 22:41:07 by selrhair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= cc
READLINE = -I /Users/selrhair/Desktop/readline/8.2.1/lib/
# CFLAGS	=  -Wall -Wextra -Werror
RM		= rm -rf
# HEADER	= -I./inc

# colors
NONE	= \033[0m
YALLOW	= \033[1;93m
Green	= \033[1;32m	

# src files
SRCS	= main.c utils_1.c utils_2.c utils_3.c utils_4.c


# SRCS	= $(addprefix ./src/, $(SRC)) main.c

# obj files
OBJS	= $(SRCS:.c=.o)

		
all : $(NAME)

%.o:%.c
	@echo "$(Green)Compaling file $<$(NONE)"
	$(CC) $(CFLAGS) $(READLINE) -c $^ -o $@

$(NAME) : $(OBJS) $(LIBFT)
	@echo  "$(YALLOW)\n[$@]$(NONE)"
	$(CC) $(CFLAGS) $(OBJS) -o $@ -lreadline

git :
		make fclean && git add . && git commit -m "update" && git push -u origin main

clean :
	@echo "$(Green)Cleaning obj files....$(NONE)"
	$(RM) $(OBJS)

fclean : clean
	@echo "$(Green)Clean all ....$(NONE)"
	$(RM) $(NAME)

re: fclean all

ss : all clean clear

clear: 
		clear