#include "../../includes/ft_lib_push_swap.h"

void ft_checking_pos(t_env *vn, int pos)
{
  int rank;

  rank = val_to_rank(vn, vn->a->tab[in(vn->a->bot + pos)]);
  ft_checking(vn, rank);
}

int ft_calc_head(t_env *vn, int rank, t_ps *ps)
{
  int pos;
  int bot;
  int count;
  int tmp;

  count = 1;
  bot = vn->a->bot;
  tmp = rank_to_pos_a(vn, rank);
  pos = tmp - 1;
  while (pos >= 0)
  {
    if (vn->a->tab[in(bot + pos)] > vn->a->tab[in(bot + pos + 1)])
    {
      count++;
    }
    pos--;
  }
  return (count);
}

void ft_select_to_b(t_env *vn, t_ps *ps)
{
  int i;
  int j;
  int tmp;
  int pos;
  int bot;

  i = 0;
  bot = vn->a->bot;
  ps->head = i;
  ps->moves = ft_calc_head(vn, ps->head, ps);
  while (i < vn->len)
  {
    tmp = ft_calc_head(vn, i, ps);
    if (ps->moves < tmp || (ps->moves == tmp && i < ps->head))
     {
       ps->moves = tmp;
       ps->head = i;
     }
    i++;
  }
  //ft_checking(vn, rank_to_pos_a(vn, ps->head));

  pos = rank_to_pos_a(vn, ps->head);
  ft_checking_pos(vn, pos);
  tmp = pos;
  pos--;
  while (pos >= 0)
  {
    if (vn->a->tab[in(bot + pos)] > vn->a->tab[in(bot + tmp)])
    {
      ft_checking_pos(vn, pos);
      tmp = pos;
    }
    pos--;
  }
}

int ft_is_true(t_env *vn, int val)
{
  int i;

  i = 0;
  while (i <= vn->len - 1)
  {
    if (vn->org[i] == val)
    {
      return (vn->cb[i]);
    }
    i++;
  }
  return (-1);
}

int ft_is_f_in_a(t_env *vn)
{
  int i;
  int len;

  i = 0;
  len = st_nb_elem(vn->a);
  while (i < len)
  {
    if (!ft_is_true(vn, vn->a->tab[in(vn->a->bot + i)]))
      return (1);
    i++;
  }
  return (0);
}

void ft_a_to_b(t_env *vn, t_ps *ps)
{
  while (ft_is_f_in_a(vn))
  {
    if (!ft_is_true(vn, vn->a->tab[in(vn->a->top)]))
    {
      ps->ins = ft_strjoin_customed(ps->ins, "pb\n");
      pb(vn->b, vn->a);
    }
    else
    {
      ps->ins = ft_strjoin_customed(ps->ins, "ra\n");
      ra(vn->a);
    }
  }
}

int ft_is_done(t_env *vn, t_ps *ps)
{
  int len;
  int rank;
  int pos_upper;
  int pos_lower;
  int pos;

  rank = 0;
  len = st_nb_elem(vn->a);
  while (rank < len)
  {
    pos = rank_to_pos_a(vn, rank);
    if (rank != pos)
      return (0);
    rank++;
  }
  return (1);
}

void ft_ending(t_env *vn, t_ps *ps)
{
  int len;
  int rank;
  int pos_upper;
  int pos_lower;
  int pos;

  rank = 0;
  len = st_nb_elem(vn->a);
  while (rank < len)
  {
    pos_upper = rank_to_pos_a(vn, rank + 1);
    pos_lower = rank_to_pos_a(vn, rank - 1);
    pos = rank_to_pos_a(vn, rank);
    if ((rank == 0 && pos != pos_upper + 1)
    || (rank == len - 1 && pos != pos_lower - 1))
      put_elem_to_suit_pos(vn, rank, ps);
    if (pos != pos_upper + 1 && pos != pos_lower - 1)
      put_elem_to_suit_pos(vn, rank, ps);
    rank++;
  }
  ft_align_a(vn, ps);
}

/*int ft_is_done2(t_env *vn, t_ps *ps)
{
  int rank;

  if (val_to_rank(vn, vn->a->tab[in(vn->bot)]) == vn->len - 1)
  {

  }
  if (val_to_rank(vn, vn->a->tab[in(vn->top)]) == 0)
  {

  }
  return (-1);
}*/

void ft_ending2(t_env *vn, t_ps *ps)
{
  int len;
  int rank;
  int pos;

  rank = 0;
  len = st_nb_elem(vn->a);
  while (rank < len)
  {
    pos = rank_to_pos_a(vn, rank);
    if (rank != pos)
      put_elem_to_suit_pos(vn, rank, ps);
    rank++;
  }
}

void ft_apply(t_env *vn, t_ps *ps)
{
  char **tab;
  int i;

  tab = ft_strsplit(ps->ins, '\n');
  i = 0;
  while (tab[i] != NULL)
  {
    if (!ft_strcmp(tab[i], "pb"))
      pb(vn->b, vn->a);
    if (!ft_strcmp(tab[i], "pa"))
      pa(vn->a, vn->b);
    if (!ft_strcmp(tab[i], "sa"))
      sa(vn->a);
    if (!ft_strcmp(tab[i], "sb"))
      sb(vn->b);
    if (!ft_strcmp(tab[i], "ss"))
      ss(vn->a, vn->b);
    if (!ft_strcmp(tab[i], "ra"))
      ra(vn->a);
    if (!ft_strcmp(tab[i], "rb"))
      rb(vn->b);
    if (!ft_strcmp(tab[i], "rr"))
      rr(vn->a, vn->b);
    if (!ft_strcmp(tab[i], "rra"))
      rra(vn->a);
    if (!ft_strcmp(tab[i], "rrb"))
      rrb(vn->b);
    if (!ft_strcmp(tab[i], "rrr"))
      rrr(vn->a, vn->b);
    i++;
  }
}

void ft_common(t_ps *ps)
{
  int i;
  int j;
  char **ta = NULL;
  char **tb = NULL;

  ta = ft_strsplit(ps->ins_a, '\n');
  tb = ft_strsplit(ps->ins_b, '\n');
  i = 0;
  j = 0;

  while (ta[i] != NULL)
  {
    if (tb[j] != NULL && !ft_strcmp(ta[i], "ra") && !ft_strcmp(tb[j], "rb"))
    {
      ps->ins = ft_strjoin_customed(ps->ins, "rr\n");
      i++;
      if (tb[j] != NULL)
        j++;
      continue ;
    }
    else if (tb[j] != NULL && !ft_strcmp(ta[i], "rra")
    && !ft_strcmp(tb[j], "rrb"))
    {
      ps->ins = ft_strjoin_customed(ps->ins, "rrr\n");
      i++;
      if (tb[j] != NULL)
        j++;
      continue ;
    }
    ps->ins = ft_strjoin_customed(ps->ins, ta[i]);
    ps->ins = ft_strjoin_customed(ps->ins, "\n");
    i++;
  }
  while (tb[j] != NULL)
  {
    ps->ins = ft_strjoin_customed(ps->ins, tb[j]);
    ps->ins = ft_strjoin_customed(ps->ins, "\n");
    j++;
  }
  /*while (ta[i])
  {
    ps->ins = ft_strjoin_customed(ps->ins, ta[i]);
    //ps->ins = ft_strjoin_customed(ps->ins, "\n");
    i++;
  }
  ps->ins = ft_strjoin_customed(ps->ins, "\n");
  while (tb[j])
  {
    ps->ins = ft_strjoin_customed(ps->ins, tb[j]);
    //ps->ins = ft_strjoin_customed(ps->ins, "\n");
    j++;
  }*/
}

void push_swap2(t_env *vn, t_ps *ps)
{
  //while (!ft_is_done(vn, ps))
//  {
    ft_select_to_b(vn, ps);
    ft_a_to_b(vn, ps);
  //  ft_process_a(vn, ps); //
  //  ft_process_b(vn, ps); //
    ft_select_to_a(vn, ps);


//  }
    //ft_ending(vn, ps);
    ft_align_a(vn, ps);


//      ft_ending2(vn, ps);

  printf("%s", ps->ins);
}