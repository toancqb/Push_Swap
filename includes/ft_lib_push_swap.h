/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_push_swap.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:41:40 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 21:15:23 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_PUSH_SWAP_H
# define FT_LIB_PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../src/stack/st_lib_stack.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define STDIN_DEFAULT 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648

void			pa(t_st **st_a, t_st **st_b);
void			pb(t_st **st_a, t_st **st_b);
void			sa(t_st *st_a);
void			sb(t_st *st_b);
void			ss(t_st *st_a, t_st *st_b);

void			ra(t_st **st_a);
void			rb(t_st **st_b);
void			rr(t_st **st_a, t_st **st_b);

void			rra(t_st **st_a);
void			rrb(t_st **st_b);
void			rrr(t_st **st_a, t_st **st_b);

void			f_p(int val);
void			ft_error();
void			ft_ok();
void			ft_ko();
void			ft_sort_array(int *arr, int len);
int				ft_place(t_st *st, int val, int len);
int				is_sorted_st(t_st *a, int len);
int				ft_rev(t_st *a);
int				is_rank_in_a(t_st *a, int rank);
char			*ft_strjoin_customed(char *str, char *buf);
void			find_r_minmax(t_st *a, int *r_max, int *r_min, int rank);
void			ft_1(t_st *a, t_st *b, int *m, int *r);
void			ft_2(t_elem **e, int *index, int c);
int				ft_calc_b_to_a(t_st *a, t_st *b, int *rr, int *check);
void			ft_free_2arr(long **i, int **j);
void			ft_free_one_tab(char ***tab);
void			ft_free_tab(char ***ta, char ***tb);
void			ft_free_2intarr(int **best, int **p);
int				fcmax(t_st *a);
void			ps_3(t_st **a, int len);
void			ps_5(t_st **a, t_st **b, int len);
void			ft_rr_rrr(char **ins_a, char **ins_b);

long			*ft_process_input(int argc, char **argv, int *len);
void			ft_init_push_swap(t_st **a, long *input, int *select, int len);
void			ft_select(int *select, int len);
void			ft_a_to_b(t_st **a, t_st **b, long *input, int *select);
void			ft_a_to_top(t_st **a, int rank, char **ins);
void			ft_a_to_top_minus(t_st **a, int rank, char **ins);
void			ft_b_to_a(t_st **a, t_st **b);
void			ft_align_a(t_st **a, int len);
void			ft_align_a_min_max(t_st **a, int len);

#endif
