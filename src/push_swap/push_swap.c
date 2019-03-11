/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:08:02 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 19:08:03 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void printf_ps(t_st *st) //
{
  int i;

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


int *ft_process_input_push(int argc, char **argv, int *len)
{
  char **tab;
  int i;
  int j;
  int *input;

  *len = 0;
  if (argc >= 2)
  {
    tab = ft_strsplit(argv[1], ' ');
    while (tab[*len] != NULL)
      (*len)++;
    input = (int*)malloc(sizeof(int) * (*len));
    i = 0;
    while (i < *len && tab[i])
    {
      input[i] = (int)ft_atoi(tab[i]);
      i++;
    }
    return (input);
  }
  else
    ft_error();
  return (NULL);
}

void env_init(t_env *vn)
{
  vn->a = st_init();
  vn->b = st_init();
  vn->len = 0;
  vn->org = NULL;
  vn->res = NULL;
  vn->ins = NULL;
}

void ft_init_push_swap(t_env *vn, int len)
{
  int i;
  int tmp;

  i = len - 1;
  while (i >= 0)
  {
    tmp = (vn->org)[i];
    st_push(vn->a, tmp);
    i--;
  }
  if (st_is_empty(vn->a))
    ft_ok();
}

int main(int argc, char *argv[])
{
	t_env *vn;

  vn = (t_env*)malloc(sizeof(t_env));
  env_init(vn);
	vn->org = ft_process_input_push(argc, argv, &(vn->len));
	ft_assign_res(vn);
	ft_init_push_swap(vn, vn->len);

  /*printf_ps(vn->a);
  ra(vn->a);
  pb(vn->b, vn->a);
  qsort_interative(vn->a->tab, vn->a->bot, vn->a->top);
  printf_ps(vn->a);*/

}
