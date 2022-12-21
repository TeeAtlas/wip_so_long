# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 15:17:12 by taboterm          #+#    #+#              #
#    Updated: 2022/12/20 18:22:34 by taboterm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# source id
SRCS = window.c \
			read_map.c \

OBJS = $(SRCS:%.c=%.o)

# Compiling info
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
MFLAGS = -L${MLX_DIR} -I$(MLX_PATH) -lmlx -lm -framework OpenGL -framework AppKit

# Target output
NAME = so_long

RM = rm -f

# Including Minilibx 
MLX_DIR = ./minilibx_opengl_20191021/
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a
LIBFT = libft/libft.a

# make target executable
$(NAME): $(OBJS)
	make -C ./minilibx_opengl_20191021
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) -o $(NAME) $(LIBFT)

# Make desired targets
all:	${NAME}

clean:
	make clean -C ./minilibx_opengl_20191021
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft
	/bin/rm -f *.o $(NAME)

re: fclean all

.PHONY: clean fclean all re
