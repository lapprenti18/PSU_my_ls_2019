##
## EPITECH PROJECT, 2019
## Bistromatic
## File description:
## Makefile
##

SRC	=	main.c	\
		just_ls.c	\
		parsing.c	\
		my_putstr.c	\
		my_put_nbr.c	\
		ls_l_no_arg.c	\
		cat.c	\
		my_strlen.c	\

NAME	=	my_ls

OBJ	=	libmy.a

CSFML	=	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

VG	=	-g3

ERROR	=	-Wall -W -Wextra

all	:	$(OBJ)

$(OBJ)	:
	gcc -o $(NAME) $(SRC) $(ERROR) $(VG)

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
