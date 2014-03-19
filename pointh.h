/*
** pointh.h for  in /u/all/brenne_t/cu/rendu/c/malloc
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Tue Feb 17 14:15:21 2009 thomas brennetot
** Last update Sat Mar 28 19:14:06 2009 thomas brennetot
*/

#ifndef __POINTH_H__
# define __POINTH_H__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define	YES	42
#define	NO	24
#define	FAIL	((void *) -1)

typedef	struct		s_malloc
{
  unsigned int		size_block;
  unsigned int		size_ask;
  int			use;
  struct s_malloc	*next;
}			t_malloc;

void			show_alloc_mem(void);
int			power_sqrt(int popo);
void			my_putstr(char *str);
t_malloc		*find_associate_struct_of_alloc_space(void *ptr);
void			my_free(t_malloc *st_malloc);

t_malloc		*gl_malloc;

#endif
