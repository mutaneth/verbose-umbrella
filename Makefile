NAME = fillit
SRC_PATH = ./source/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
INC_LIB_H_PATH = ./includes/libft/includes
LIB_PATH = ./includes/libft/

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
INC_LH_PATH = $(addprefix -I, $(INC_LIB_H_PATH))

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
	gcc -o $(NAME) $(OBJ) -lm -L $(LIB_PATH) -lft
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	gcc -Wall -Werror -Wextra $(INC) $(INC_LH_PATH) -o $@ -c $<
lib_refresh:
	make -C $(LIB_PATH)

norm:
	echo "$(YELLOW)"
	norminette -R CheckForbiddenSourceHeader
	echo "$(NORMAL)"

clean:
	/bin/rm -rf $(OBJ_PATH)
	make clean -C $(LIB_PATH)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all
