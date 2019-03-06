/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:14:29 by qtran             #+#    #+#             */
/*   Updated: 2019/03/06 16:14:30 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int nb_move_a_to_b(t_env *vn, int a_pos)
{
  int st_len;

  st_len = st_nb_elem(vn->a) - 1;
  st_len += (st_len % 2) ? 1 : 0;
  if (a_pos == (vn->a)->top)
    return (1);
  if (a_pos == (vn->a)->bot)
    return (2);
  if (a_pos >= st_len)
    return ((vn->a)->top - a_pos + 1);
  if (a_pos < st_len)
    return (a_pos - (vn->a)->bot + 2);
  return (0);
}
