/*
** power_sqrt.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/malloc
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Thu Mar  5 13:25:29 2009 thomas brennetot
** Last update Thu Mar  5 17:07:38 2009 thomas brennetot
*/

#include "pointh.h"

int	power_sqrt_next(int popo)
{
  int	result;
  int	i;

  i = 0;
  result = 1;
  while (i < popo)
    {
      result *= 2;
      i++;
    }
  return (result);
}

int	power_sqrt(int popo)
{
  int	i;

  i = 0;
  while (popo > power_sqrt_next(i))
    i++;
  return (power_sqrt_next(i));
}
