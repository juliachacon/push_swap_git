# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julia <julia@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/21 16:33:56 by julia             #+#    #+#              #
#    Updated: 2026/02/28 16:13:05 by julia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julia <julia@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/21                                #+#    #+#            #
#    Updated: 2026/02/21                                ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
INCLUDES    := -Iincludes -Ilibft

LIBFT_DIR   := libft
LIBFT_A     := $(LIBFT_DIR)/libft.a

SRC_DIR     := src
OBJ_DIR     := obj

SRCS        := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parse_args.c \
	$(SRC_DIR)/parse_utils.c \
	$(SRC_DIR)/parse_validate.c \
	$(SRC_DIR)/stack_build.c \
	$(SRC_DIR)/push_swap.c

OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

# Compile libft
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

# Compile objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

