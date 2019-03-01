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

void quick_sort(int *tab, int l, int h);

void print_test(int *tab, int len)
{
  int i;

  i = 0;
  while (i < len)
  {
    printf("%d\n", tab[i]);
    i++;
  }
  printf("\n<===>\n");
}

void printf_stps(t_st *st)
{
  int i;

  //printf("is empty: %d | nb elem: %d\n", st_is_empty(st), st_nb_elem(st));
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

// This function return the sorted stack
void sortStack(t_st *a, t_st *b)
{
    while (!st_is_empty(a))
    {
        // pop out the first element
        int tmp = a->tab[in(a->top)];
        st_pop(a);
        // while temporary stack is not empty and top
        // of stack is greater than temp
        while (!st_is_empty(b) && b->tab[in(b->top)] > tmp)
        {
            // pop from temporary stack and push
            // it to the input stack
            st_push(a, st_pop(b)); //<----
            //pa(a, b);
        }

        st_push(b, tmp);
        //pb(b, a);
    }
    while (!st_is_empty(b))
    {
      st_push(a, st_pop(b)); //<-----
    }
  }

int main(int argc, char *argv[])
{
  int *input;
  int len;
  t_st *a;
  t_st *b;

  a = st_init();
  b = st_init();
  input = ft_process_input(argc, argv, &len);
  ft_init_checker(a, b, input, len);
  printf_stps(a);
   sortStack(a, b);
  printf_stps(a);
  //print_test(input, len);

  //quick_sort(input, 0, len - 1);
  //print_test(input, len);
}
