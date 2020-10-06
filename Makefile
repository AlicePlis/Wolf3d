#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsonja <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 14:12:39 by jsonja            #+#    #+#              #
#    Updated: 2020/02/13 13:24:47 by jsonja           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LIB_PATH = ./libft/
LIBMLX_PATH = ./minilibx_macos/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I , $(INC_PATH))
HEADERS = $(addprefix $(INC_PATH), $(INC_NAME))
LIBFT = $(LIB_PATH)libft.a
LIBMLX = $(LIBMLX_PATH)libmlx.a
FRAME = -framework OpenGL -framework AppKit
FLAGS =  -Wall -Wextra -Werror
SRC_NAME = 	read_map.c \
			main.c \
			key_press.c \
			draw.c \
			draw_wall.c \
			video_section.c \
			mouse.c \

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = wolf3d.h

all: libft_update $(NAME)

libft_update: mlx_update
		make -C $(LIB_PATH)

mlx_update:
		make -C $(LIBMLX_PATH)

$(NAME): $(OBJ) $(LIBFT)
		gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(FRAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
		mkdir -p $(OBJ_PATH)
		gcc $(FLAGS) $(INC) -o $@ -c $<

clean:
		rm -rf $(OBJ_PATH)
		make clean -C $(LIB_PATH)
		make clean -C $(LIBMLX_PATH)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIB_PATH)

re: fclean all