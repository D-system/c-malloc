/*
** free.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/malloc
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Fri Mar 27 16:30:55 2009 thomas brennetot
** Last update Sun Mar 29 22:29:59 2009 thomas brennetot
*/

#include "pointh.h"

void		my_free(t_malloc *st_malloc)
{
  if (st_malloc == NULL)
    return ;
  st_malloc->use = NO;
}

void		free(void *ptr)
{
  t_malloc	*st_malloc;

  return ;
  if ((st_malloc = find_associate_struct_of_alloc_space(ptr)) == NULL)
    my_putstr("free(): warning: junk pointer, too high to make sense\n");
  my_free(st_malloc);
}
