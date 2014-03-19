/*
** show_alloc_mem.c for  in /u/all/brenne_t/cu/rendu/c/malloc
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Wed Mar 25 16:29:30 2009 thomas brennetot
** Last update Sat Mar 28 17:35:32 2009 thomas brennetot
*/

#include "pointh.h"


void	my_putstr(char *str)
{
  write(1, str, strlen(str));
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      my_put_nbr(-nb);
    }
  else
    {
      if (nb < 10)
	my_putchar(nb + '0');
      else
	{
	  my_put_nbr(nb / 10);
	  my_putchar((nb % 10) + '0');
	}
    }
  return ;
}


void		show_alloc_mem()
{
  t_malloc	*st_malloc;
  int		i = 1;

  st_malloc = gl_malloc;
  while (st_malloc != NULL)
    {
      my_putstr("size_ask\t");
      my_put_nbr(st_malloc->size_ask);
      my_putstr("\tsize_block\t");
      my_put_nbr(st_malloc->size_block);
      my_putstr("\tsize avec header\t");
      my_put_nbr(st_malloc->size_block + sizeof(*st_malloc));
      my_putstr("\tlocation\t");
      my_put_nbr((int)st_malloc);
      my_putstr("\tnb\t");
      my_put_nbr(i++);
      my_putstr("\n");
      st_malloc = st_malloc->next;
    }
  my_putstr("\n\n");
}

