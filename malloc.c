/*
** main.c for  in /u/all/brenne_t/cu/rendu/proj/malloc
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Mon Feb  9 11:30:26 2009 thomas brennetot
** Last update Sun Mar 29 16:57:13 2009 thomas brennetot
*/

#include "pointh.h"

void		*first_malloc(size_t size)
{
  t_malloc	st_new;

  gl_malloc = sbrk(power_sqrt(sizeof(st_new) + size));
  if (gl_malloc == FAIL)
    return (NULL);
  st_new.size_ask = size;
  st_new.size_block = (int)sbrk(0) - (int)gl_malloc - sizeof(st_new);
  st_new.use = NO;
  st_new.next = NULL;
  *gl_malloc = st_new;
  return (malloc(size));
}

void		*find_space(size_t size)
{
  t_malloc	*st_malloc;

  st_malloc = gl_malloc;
  while (st_malloc != NULL)
    {
      if (st_malloc->use == NO)
	if (st_malloc->size_block <= size)
	  {

	    /* FRAGMENTER LE SEGMENT */

	    st_malloc->use = YES;
	    return (st_malloc + 1);
	  }
      st_malloc = st_malloc->next;
    }
  return (NULL);
}

void		*create_space(size_t size)
{
  t_malloc	*st_malloc;
  int		total_size;

  st_malloc = gl_malloc;
  while (st_malloc->next != NULL)
    st_malloc = st_malloc->next;
  total_size = power_sqrt(size + sizeof(*st_malloc));
  if ((st_malloc->next = sbrk(total_size)) == FAIL)
    {
      st_malloc->next = NULL;
      gl_malloc = FAIL;
      return (NULL);
    }
  st_malloc = st_malloc->next;
  st_malloc->size_block = (int)sbrk(0) - (int)st_malloc - sizeof(*st_malloc);
  st_malloc->size_ask = size;
  st_malloc->use = YES;
  st_malloc->next = NULL;
  return (st_malloc + 1);
}

void		*malloc(size_t size)
{
  void		*ptr;

  if (gl_malloc == FAIL)
    return (NULL);
  if (gl_malloc == NULL)
    ptr = first_malloc(size);
  else if ((ptr = find_space(size)) == NULL)
    ptr = create_space(size);
  return (ptr);
}
