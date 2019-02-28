/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:13:31 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 15:13:33 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

t_st *st_init()
{
  t_st *st;
  int i;

  st = (t_st*)malloc(sizeof(t_st));
  st->top = -1;
  st->bot = 0;
  i = 0;
  while (i < NB_MAX)
  {
    st->tab[i] = -1;
    i++;
  }
  return (st);
}