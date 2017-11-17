# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealrick <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 03:01:38 by ealrick           #+#    #+#              #
#    Updated: 2017/10/31 03:01:41 by ealrick          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

INC_DIR = ./

SRC_DIR = .src/

SRC_FILES = main.c \
			start.c \
			keys.c \
			wolf.c \
			calc.c \
			draw.c \
			colors/color.c \
			colors/color1.c \
			pos.c \
			teleport.c

O_FILES = $(SRC_FILES:.c=.o)

CC = gcc

CC_FLAGS = -Wall -Werror -Wextra -lm -O3

I_LIBFT = -I libft/ -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework OpenGL

LIBFT = -L libft $(I_LIBFT) -lft

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@$(CC) $(CC_FLAGS) $^ -I $(INC_DIR) $(LIBFT) -o $(NAME)
	@echo $(NAME) created.

%.o: $(SRC_DIR)%.c
	@$(CC) $(CC_FLAGS)  -I$(INC_DIR) -o $@ -c $< $(I_LIBFT)

clean:
	@make clean -C libft
	@rm -f $(O_FILES)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo $(NAME) Deleted.

re: fclean all

.PHONY: all clean fclean re
