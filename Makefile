##
## Makefile for bmp_loader in /home/lombar_e/github/bmp_loader
##
## Made by Thomas Lombard
## Login   <lombar_e@epitech.net>
##
## Started on  Tue Jan 10 15:21:32 2017 Thomas Lombard
## Last update Tue Jan 10 15:21:32 2017 Thomas Lombard
##

NAME	= test

CFLAGS	+= -W -Wall -Wextra
CFLAGS	+= -I include/
CFLAGS	+= -Os -Ofast

LDFLAGS	+= -L./src/ -lbmp

RM	=  rm -f

CC	=  clang

PROJ_SRC=  main.c

PROJ	=  $(PROJ_SRC:.c=.o)

$(NAME): $(PROJ) $(GRAPH)
	@ make -C src/ && echo "Compilation de la librairie bmp"
	$(CC) -o $(NAME) $(PROJ) $(LDFLAGS)

all: $(NAME)

clean:
	@ make clean -C src/ && echo "Clean de la librairie bmp"
	$(RM) $(LIB) $(PROJ) $(GRAPH) $(LIB_NAME)

fclean: clean
	@ make fclean -C src/ && echo "Fclean de la librairie bmp"
	$(RM) $(NAME)

re: fclean all
