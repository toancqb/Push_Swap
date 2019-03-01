/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:40:45 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 14:41:06 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib_push_swap.h"
#include <stdio.h>

void print_st(t_st *st)
{
  int i;

  printf("is empty: %d | nb elem: %d\n", st_is_empty(st), st_nb_elem(st));
  if (st_is_empty(st) == 0)
  {
    i = st->top;
    while (i >= st->bot)
    {
      printf("(%d)\n", st->tab[in(i)]);
      i--;
    }
  }
  printf("\n=--=\n");
}

int main(void)
{
  t_st *a, *b;

  a = st_init();
  b = st_init();

  st_push(a, 2);
  st_push(a, 3);
  st_push(a, 1);
  st_push(a, 4);
  st_push(a, 5);

  print_st(a); print_st(b);

  /*ra(a);
  ra(a);
  pb(b, a);
  ra(a);
  pb(b, a);
  sa(a);
  ra(a);
  sa(a);
  rra(a);
  sa(a);
  pa(a, b); pa(a, b);*/
  ra(a); ra(a);
  pb(b, a);
  ra(a);
  pb(b, a);
  sa(a);
  rra(a);
  pa(a, b);
  pa(a, b);

  print_st(a); print_st(b);

}
