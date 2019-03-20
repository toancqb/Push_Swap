#include "../../includes/ft_lib_push_swap.h"

void pos_upper_b(t_env *vn, int pos, int len, t_ps *ps)
{
  while (pos < len - 1)
  {
    ps->ins_b = ft_strjoin_customed(ps->ins_b, "rb\n");
    ps->next_move++;
    rb(vn->b);
    pos++;
  }
  ps->next_move++;
  ps->ins_b = ft_strjoin_customed(ps->ins_b, "pa\n");
  pa(vn->a, vn->b);
}

void pos_lower_b(t_env *vn, int pos, int len, t_ps *ps)
{
  while (pos >= 0)
  {
    ps->ins_b = ft_strjoin_customed(ps->ins_b, "rrb\n");
    ps->next_move++;
    rrb(vn->b);
    pos--;
  }
  ps->next_move++;
  ps->ins_b = ft_strjoin_customed(ps->ins_b, "pa\n");
  pa(vn->a, vn->b);
}

int push_b_to_a(t_env *vn, int pos, t_ps *ps)
{
  int place;
  int len;

  len = st_nb_elem(vn->b);
  place = place_elem(vn->b, pos);
  if (place == 0)
  {
    ps->next_move++;
    ps->ins_b = ft_strjoin_customed(ps->ins_b, "pa\n");
    pa(vn->a, vn->b);
  }
  else if (place == 1)
  {
    pos_upper_b(vn, pos, len, ps);
  }
  else if(place == 3)
  {
    ps->next_move+= 2;
    ps->ins_b = ft_strjoin_customed(ps->ins_b, "rrb\npa\n");
    rrb(vn->b);
    pa(vn->a, vn->b);
  }
  else
  {
    pos_lower_b(vn, pos, len, ps);
  }
  return (ps->next_move);
}
