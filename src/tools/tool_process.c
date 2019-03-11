/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:48:30 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 15:48:31 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int in(int n)
{
  if (n < 0)
    return (n % NB_MAX + NB_MAX);
  return (n % NB_MAX);
}

void swap(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

int val_to_pos(t_st *a, int n)
{
  int i;

  i = a->bot;
  while (i <= a->top)
  {
    if (n == a->tab[in(i)])
      return (i - a->bot);
    i++;
  }
  return (-1);
}
