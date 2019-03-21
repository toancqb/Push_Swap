#include "../../includes/ft_lib_push_swap.h"

int calc_upper_b(t_env *vn, int pos, int len, t_ps *ps)
{
  int count;

  count = 0;
  while (pos < len - 1)
  {
    count++;
    pos++;
  }
  return (count);
}

int calc_lower_b(t_env *vn, int pos, int len, t_ps *ps)
{
  int count;

  count = 0;
  while (pos >= 0)
  {
    count++;
    pos--;
  }
  return (count);
}

int calc_pos_to_top_a(t_env *vn, int rank, t_ps *ps)
{
  int place;
  int len;
  int pos;

  len = st_nb_elem(vn->a);
  while (rank_to_pos_a(vn, rank) == -1)
    rank++;
  pos = rank_to_pos_a(vn, rank);
  place = place_elem(vn->a, pos);
  if (place == 0)
    return (0);
  else if (place == 1)
    return (calc_upper_b(vn, pos, len, ps));
  else if (place == 3)
    return (1);
  else
    return (calc_lower_b(vn, pos, len, ps));

}

int calc_elem_to_suit_pos_from_b(t_env *vn, int pos, t_ps *ps)
{
  int place;
  int len;
  int rank;

  rank = val_to_rank(vn, vn->b->tab[in(vn->b->bot + pos)]);
  len = st_nb_elem(vn->b);
  place = place_elem(vn->b, pos);
  if (place == 0)
    return (1 + calc_pos_to_top_a(vn, rank + 1, ps));
  else if (place == 1)
    return (len - pos + calc_pos_to_top_a(vn, rank + 1, ps));
  else if (place == 3)
    return (2 + calc_pos_to_top_a(vn, rank + 1, ps));
  else
    return (pos + 1 + calc_pos_to_top_a(vn, rank + 1, ps));
}

void ft_select_to_a(t_env *vn, t_ps *ps)
{
  int pos;
  int rank;
  int len;
  int ins_min;

  while (st_nb_elem(vn->b) != 0)
  {
    len = st_nb_elem(vn->b);
    pos = len - 1;
    ins_min = calc_elem_to_suit_pos_from_b(vn, pos, ps);
    ps->curr = pos;
    pos--;
    while (pos >= 0)
    {
      if (ins_min > calc_elem_to_suit_pos_from_b(vn, pos, ps))
      {
        ps->curr = pos;
      }
      pos--;
    }
    rank = val_to_rank(vn, vn->b->tab[in(vn->b->bot + ps->curr)]);
    if (rank < vn->len - 1)
    {
      rank++;
      while (rank_to_pos_a(vn, rank) == -1)
        rank++;
      if (rank_to_pos_a(vn, rank) != st_nb_elem(vn->a) - 1)
        pos_to_top(vn, rank_to_pos_a(vn, rank), ps);
    }
    push_b_to_a(vn, ps->curr, ps);
    /*ft_common(ps);
    free(ps->ins_a); ps->ins_a = ft_strnew(1);
    free(ps->ins_b); ps->ins_b = ft_strnew(1);*/
  }


  //ft_apply(vn, ps);
}
