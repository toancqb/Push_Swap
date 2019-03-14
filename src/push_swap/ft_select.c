#include "../../includes/ft_lib_push_swap.h"

void upper(t_env *vn, int pos, int len, t_ps *ps)
{
  while (pos < len - 1)
  {
    ps->ins = ft_strjoin_customed(ps->ins, "ra\n");
    ps->next_move++;
    ra(vn->a);
    pos++;
  }
}

void lower(t_env *vn, int pos, int len, t_ps *ps)
{
  while (pos >= 0)
  {
    ps->ins = ft_strjoin_customed(ps->ins, "rra\n");
    ps->next_move++;
    rra(vn->a);
    pos--;
  }
}

int pos_to_top(t_env *vn, int pos, t_ps *ps)
{
  int place;
  int len;

  len = st_nb_elem(vn->a);
  place = place_elem(vn->a, pos);
  if (place == 1)
  {
    upper(vn, pos, len, ps);
  }
  else if(place == 3)
  {
    ps->next_move++;
    ps->ins = ft_strjoin_customed(ps->ins, "rra\n");
    rra(vn->a);
  }
  else
  {
    lower(vn, pos, len, ps);
  }
  return (ps->next_move);
}
/*
* Try new algo:
* calc for each elem by rank, choose the smallest ins
* repeat
*
*/

void push_swap(t_env *vn, t_ps *ps)
{
  int pos;

  ps->head = vn->len - 1;
  ps->tail_min = ps->head - 1;
  while (ps->tail_min >= 0)
  {
    pos = rank_to_pos_a(vn, ps->tail_min);
    push_a_to_b(vn, pos, ps);
    pos_to_top(vn, rank_to_pos_a(vn, ps->head), ps);
    ps->next_move++;
    ps->ins = ft_strjoin_customed(ps->ins, "pa\n");
    pa(vn->a, vn->b);
    ps->head--;
    ps->tail_min--;
  }
  printf("%s", ps->ins);
}
