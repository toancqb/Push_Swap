/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:52:21 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 16:52:22 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void ft_init_checker(t_st *a, t_st *b, int *input, int len)
{
  int i;

  a = st_init();
  b = st_init();
  i = 0;
  while (i < len)
  {
    //printf("\n(%d)\n", input[i]);
    st_push(a, (int)input[i]);
    i++;
  }
  if (st_is_empty(a))
    ft_ok();
}