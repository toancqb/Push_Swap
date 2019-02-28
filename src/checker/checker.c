/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:41:11 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 14:41:33 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int main(int argc, char *argv[])
{
  t_st *a;
  t_st *b;
  char *line;
  int *input;
  ssize_t size;
  int len;

  len = 0;
  input = NULL;
  ft_process_input(argc, argv, input, &len);
  ft_init_checker(a, b, input, len);
  free(input);
  while ((size = get_next_line((const int)STDIN_DEFAULT, &line)) > 0)
  {
    ft_command(line, a, b);
    free(line);
  }
  if (size == -1)
    ft_error();

  return (0);
}
