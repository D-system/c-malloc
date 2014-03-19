/*
** realloc.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/malloc
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Fri Mar 27 15:16:59 2009 thomas brennetot
** Last update Sat Mar 28 19:10:25 2009 thomas brennetot
*/

#include "pointh.h"

void		*realloc(void *ptr, size_t size)
{
  void		*ptr_new;
  t_malloc	*st_malloc;

  if (ptr == NULL)
    return (malloc(size));
  st_malloc = find_associate_struct_of_alloc_space(ptr);
  if (st_malloc == NULL)
    {
      my_putstr("realloc(toto): warning: junk pointer, too high to make sense\n");
      return (NULL);
    }
  if (st_malloc->size_block < size)
    {
      ptr_new = malloc(size);
      memmove(ptr_new, ptr, st_malloc->size_ask);
      my_free(st_malloc);
    }
  else
    {
      st_malloc->size_ask = size;
      ptr_new = st_malloc;
    }
  return (ptr_new);
}
