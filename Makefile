# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 14:15:45 by miltavar          #+#    #+#              #
#    Updated: 2025/06/11 15:18:58 by miltavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -Ilibft/includes -Iincludes
SRCS		= srcs/push_swap.c srcs/args_check.c srcs/utils.c \
				srcs/lists_utils.c srcs/lists_utils_2.c \
				srcs/utils_2.c srcs/specifics.c srcs/movements.c \
				srcs/movements_2.c srcs/big_sort.c srcs/tab_utils.c
LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
