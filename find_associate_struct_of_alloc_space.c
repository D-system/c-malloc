
/*
** find_associate_struct_of_alloc_space.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/malloc
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Fri Mar 27 15:21:46 2009 thomas brennetot
** Last update Sat Mar 28 18:09:12 2009 thomas brennetot
*/

#include <stdlib.h>
#include "pointh.h"

t_malloc	*find_associate_struct_of_alloc_space(void *ptr)
{
  t_malloc	*st_malloc;

  if (ptr == NULL)
    return (NULL);
  st_malloc = gl_malloc;
  while (st_malloc != NULL)
    {
      if ((char *)ptr >= (char *)st_malloc &&
	  (char *)ptr <= (char *)(st_malloc + st_malloc->size_block))
	return (st_malloc);
      st_malloc = st_malloc->next;
    }
  return (NULL);
}
