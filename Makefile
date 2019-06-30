NAME= fillit
SRC = main.c validate.c put_in.c map_creator.c
SRC_G= main_valid.c
HEADER = ./libft 
CFLAG = -Wall -Wextra -Werror

all:
	gcc -g $(CFLAG) $(SRC)  -I$(HEADER) -I./libft  ../fillit//libft/libft.a -o $(NAME)
other:
	gcc $(CFLAG) $(SRC_G) -I$(HEADER) -I./libft  ../libft/libft.a -o $(NAME)
clean:
	rm $(NAME)

fclean: clean
	ls
re: fclean
	all
