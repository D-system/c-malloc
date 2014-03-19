##
## Makefile for  in /u/all/brenne_t/cu/rendu/c/malloc
##
## Made by thomas brennetot
## Login   <brenne_t@epitech.net>
##
## Started on  Mon Feb 23 15:15:53 2009 thomas brennetot
## Last update Sun Mar 29 22:08:16 2009 thomas brennetot
##

NAME		=	libmy_malloc_${HOSTTYPE}.so

SRC		=	malloc.c				\
			realloc.c				\
			free.c					\
			power_sqrt.c				\
			show_alloc_mem.c			\
			find_associate_struct_of_alloc_space.c

OBJ		=	${SRC:.c=.o}

CC		=	gcc

CFLAGS		=	-W -Wall -ansi -pedantic -D${HOSTTYPE}

$(NAME)		:	$(OBJ)
			$(CC) -shared $(SRC) -o $(NAME)
			ln -s libmy_malloc_${HOSTTYPE}.so libmy_malloc.so

all		:	$(NAME)

clean		:
			rm -rf $(OBJ)
			rm -rf *~

fclean		:	clean
			rm -f $(NAME)
			rm -f libmy_malloc.so

re		:	fclean all

.PHONY		=	all clean fclean re
