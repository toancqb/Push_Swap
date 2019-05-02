/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:40 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:18:10 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"
#include "../stack/st_lib_stack.h"

void	pa(t_st **st_a, t_st **st_b)
{
	if (st_nb_elem(*st_b) >= 1)
		st_push(st_a, st_pop(st_b));
}

void	pb(t_st **st_a, t_st **st_b)
{
	if (st_nb_elem(*st_a) >= 1)
		st_push(st_b, st_pop(st_a));
}
