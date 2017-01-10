##
## Makefile for wolf3d in /home/lombar_e/rendu/Infographie/wolf3d/src/libbmp
##
## Made by Thomas Lombard
## Login   <lombar_e@epitech.net>
##
## Started on  Tue Jan 03 16:42:46 2017 Thomas Lombard
## Last update Tue Jan 03 16:42:46 2017 Thomas Lombard
##

NAME		=  libbmp.a

CFLAGS		+= -W -Wall -Wextra
CFLAGS		+= -Os -Ofast

AR		=  ar rc
RAN		=  ranlib

CC		=  clang

SRC		=  load.c		\
		   parser_init.c	\
		   load_bitmap.c	\
		   bmp_calloc.c		\
		   bmp_memset.c		\
		   value_setter.c	\
		   value_setter2.c

OBJ		=  $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RAN) $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
