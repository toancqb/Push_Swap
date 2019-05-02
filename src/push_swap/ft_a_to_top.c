/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:07:19 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 17:50:04 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void	mtopa(t_st **a, int index, char **ins)
{
	int i;

	i = 0;
	while (i < index)
	{
		*ins = ft_strjoin_customed(*ins, "ra\n");
		ra(a);
		i++;
	}
}

void	mbota(t_st **a, int index, char **ins)
{
	int len_a;
	int i;

	len_a = st_nb_elem(*a);
	i = 0;
	while (i < len_a - index)
	{
		*ins = ft_strjoin_customed(*ins, "rra\n");
		rra(a);
		i++;
	}
}

void	ft_a_to_top(t_st **a, int rank, char **ins)
{
	int		len_a;
	int		index;
	t_elem	*e;

	len_a = st_nb_elem(*a);
	index = 0;
	e = (*a)->st_l;
	while (e != NULL)
	{
		if (e->r == rank)
			break ;
		index++;
		e = e->prev;
	}
	if (index == 0)
		return ;
	else if (index <= len_a / 2)
		mtopa(a, index, ins);
	else if (index > len_a / 2)
		mbota(a, index, ins);
	else
	{
		*ins = ft_strjoin_customed(*ins, "rra\n");
		rra(a);
	}
}
