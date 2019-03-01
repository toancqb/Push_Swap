/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:38:46 by qtran             #+#    #+#             */
/*   Updated: 2019/03/01 13:38:48 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void swap_qs(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int *tab, int l, int h)
{
  int x = tab[h];
  int i = (l - 1);
  int j;

  j = l;
  while (j <= h - 1)
  {
     if (tab[j] <= x)
     {
       i++;
       printf("\n[%d]%d <=> [%d]%d\n", i, tab[i], j, tab[j]);
       swap_qs(&tab[i], &tab[j]); // i  <=>  j
     }
     j++;
  }
  printf("\n[%d]%d <=> [%d]%d\n", i + 1, tab[i + 1], h, tab[h]);
  swap_qs(&tab[i + 1], &tab[h]); // i + 1  <=>  h
  return (i + 1);
}

void quick_sort(int *tab, int l, int h)
{
  t_st *st;
  int p;

  st = st_init();
  st_push(st, l);
  st_push(st, h);
  p = 0;
  while (st_is_empty(st) == 0)
  {
    h = st_pop(st);
    l = st_pop(st);
    p = partition(tab, l, h);
    if (p - 1 > l)
    {
      st_push(st, l);
      st_push(st, p - 1);
    }
    if (p + 1 < h)
    {
      st_push(st, p + 1);
      st_push(st, h);
    }
  }
  //free(st);
}
