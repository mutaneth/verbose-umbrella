# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 03:42:58 by hfalmer           #+#    #+#              #
#    Updated: 2019/07/27 21:24:19 by ddratini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all, $(NAME), norm, clean, fclean, re

#****************************************************************************#
#					SETTINGS FOR CONCLUSION IN CONSOLE 						 #
#****************************************************************************#

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
AQUA = \033[36m
GREY = \033[37m
UNDERLINE = \033[4m
NORMAL = \033[0m

#****************************************************************************#
#									FILLIT 									 #
#****************************************************************************#

NAME = fillit

SRC_PATH = ./source/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
LIB_PATH = ./includes/libft/

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

SRC_NAME =	main.c			\
			validate.c		\
			put_in.c		\
			map_creator.c	\
			putin_clone.c	\
			valhalla.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fillit.h

#****************************************************************************#
#									ALL 									 #
#****************************************************************************#

all: $(NAME)

$(NAME): $(OBJ)
	make lib_refresh
	gcc -o $(NAME) $(OBJ) -lm -L $(LIB_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	gcc -Wall -Werror -Wextra $(INC) -o $@ -c $<

#****************************************************************************#
#									OTHER			 						 #
#****************************************************************************#

lib_refresh:
	make -C $(LIB_PATH)

norm:
	@echo "$(YELLOW)"
	norminette -R CheckForbiddenSourceHeader
	echo "$(NORMAL)"

clean:
	/bin/rm -rf $(OBJ_PATH)
	make clean -C $(LIB_PATH)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all
