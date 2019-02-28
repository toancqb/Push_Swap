/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:52:15 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 16:52:17 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

/*
 * Version simple
 * ARG = "5 4 1 3 2"
 *
 */

void ft_process_input(int argc, char **argv, int *input, int *len)
{
  char **tab;
  int i;
  int j;

  *len = 0;
  if (argc >= 2)
  {
    tab = ft_strsplit(argv[1], ' ');
    while (tab[*len] != NULL)
      (*len)++;
    input = (int*)malloc(sizeof(int) * (*len));
    i = 0;
    j = *len;
    while (j >= 0 && tab[i])
    {
      input[j] = (int)ft_atoi(tab[i]);
      //printf("\n(%d)\n", input[j]);
      j--;
      i++;
    }
  }
  else
    ft_error();
}