# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfalmer <hfalmer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 20:55:59 by hfalmer           #+#    #+#              #
#    Updated: 2019/07/27 21:44:34 by ddratini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = ./source/
OBJ_PATH = ./objects/
INC_PATH = ./includes/libft/includes #includes -> inc/lib/inc/fill.h#
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

all: $(NAME)

$(NAME): $(OBJ)
	make lib_refresh
	gcc -o $(NAME) $(OBJ) -L $(LIB_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	gcc -Wall -Werror -Wextra $(INC) -o $@ -c $<

lib_refresh:
	make -C $(LIB_PATH)

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	/bin/rm -rf $(OBJ_PATH)
	make clean -C $(LIB_PATH)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all
