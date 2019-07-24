NAME = fillit
SRC = main.c 1validate.c map_creator.c put_in_last.c
KEK = put_in.c validate.c
SRC_G= main_valid.c
HEADER = ./libft 
CFLAG = -Wall -Wextra -Werror

$(NAME):
	gcc -g $(CFLAG) $(SRC)  -I$(HEADER) -I./libft  ../fillit//libft/libft.a -o $(NAME)
	gcc validate.c ../libft -o validate.o
all: $(NAME)
other:
	gcc $(CFLAG) $(SRC_G) -I$(HEADER) -I./libft  ../libft/libft.a -o $(NAME)
clean:
	rm *.o
fclean: clean
	rm $(NAME)
	ls
re: fclean
	all
