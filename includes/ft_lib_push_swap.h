/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_push_swap.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:41:40 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 14:43:10 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_PUSH_SWAP_H
# define FT_LIB_PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define NB_MAX 500
# define STDIN_DEFAULT 0

typedef struct  s_st
{
  int top;
  int bot;
  int tab[NB_MAX];
}               t_st;
/*
 *  | STACK CIRCLE -> USED FOR THE MAXIMUM 500 or 1000 NUMBERS IN PUSH_SWAP |
 *  | AND ONLY FOR PUSH_SWAP PROJET|
 *
 *  | All the index will be converted to index % NB_MAX |
 *  You are supposed to check if stack is empty or stack is full
 *  before POP or PUSH -> Because errors like that should not be silenced
 *
 * stack init: top = -1; bot = 0; tab[i] = -1;
 * stack is empty: top < bot
 * stack number elements: top - bot + 1
 * stack push: tab[index(++top)] = value
 * stack pop: return tab[index(top--)] if is_empty() == 0
 *
 */

typedef struct s_env
{
  t_st *a;
  t_st *b;
  int len;
  int *org;
  int *res;
  char **ins;
}               t_env;

int in(int n);
void swap(int *a, int *b);
void ft_error();
void ft_ok();
void ft_ko();

t_st *st_init();
int st_is_empty(t_st *st);
int st_nb_elem(t_st *st);
int st_pop(t_st *st);
void st_push(t_st *st, int value);
void st_clr(t_st *st);

void sa(t_st *st_a);
void sb(t_st *st_b);
void ss(t_st *st_a, t_st *st_b);
void pa(t_st *st_a, t_st *st_b);
void pb(t_st *st_b, t_st *st_a);
void ra(t_st *st_a);
void rb(t_st *st_b);
void rr(t_st *st_a, t_st *st_b);
void rra(t_st *st_a);
void rrb(t_st *st_b);
void rrr(t_st *st_a, t_st *st_b);

int *ft_process_input(int argc, char **argv, int *len);
void ft_init_checker(t_st *a, t_st *b, int *input, int len);
void ft_command(char *line, t_st *a, t_st *b);

void ft_assign_res(t_env *vn);

#endif
