# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/28 21:23:07 by qtran             #+#    #+#              #
#    Updated: 2019/04/28 21:23:09 by qtran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker
CC = gcc
FLAGS = -Wall -Werror -Wextra
DIR_SRC = src
LIBFT = libft
DIR_OBJS = obj
DIR_CH = $(addprefix $(DIR_SRC)/, checker)
DIR_PS = $(addprefix $(DIR_SRC)/, push_swap)
DIR_OP = $(addprefix $(DIR_SRC)/, operation)
DIR_ST = $(addprefix $(DIR_SRC)/, stack)

S_CH = checker.c

S_OP =	p_ab.c\
					rr_ab.c\
					rrr_ab.c\
					ss_ab.c\
					tool.c\
					tools.c\
					toolss.c\
					ft_init_ps.c

S_ST =	st_f_inverse_val.c\
					st_f_val.c\
					st_free_stack.c\
					st_init_elem.c\
					st_init_stack.c\
					st_nb_elem.c\
					st_pop.c\
					st_push.c

S_PS =	push_swap.c\
					ft_a_to_b.c\
					ft_a_to_top_minus.c\
					ft_a_to_top.c\
					ft_align_a.c\
					ft_b_to_a.c\
					ft_calc.c\
					ft_funcs_1.c\
					ft_funcs_2.c\
					ft_funcs_3.c\
					ft_ps_3.c\
					ft_ps_5.c\
					ft_select.c

SRC_CH = $(addprefix $(DIR_CH)/,$(S_CH))
SRC_OP = $(addprefix $(DIR_OP)/,$(S_OP))
SRC_ST = $(addprefix $(DIR_ST)/,$(S_ST))
SRC_PS = $(addprefix $(DIR_PS)/,$(S_PS))

OBJ_CH = $(addprefix $(DIR_OBJS)/,$(S_CH:.c=.o))
OBJ_OP = $(addprefix $(DIR_OBJS)/,$(S_OP:.c=.o))
OBJ_ST = $(addprefix $(DIR_OBJS)/,$(S_ST:.c=.o))
OBJ_PS = $(addprefix $(DIR_OBJS)/,$(S_PS:.c=.o))

all: $(LIBFT) $(NAME_PS) $(NAME_CH)

$(LIBFT):
	@make -C $(LIBFT)
	@mkdir -p $(DIR_OBJS)

$(NAME_PS): $(OBJ_ST) $(OBJ_OP) $(OBJ_PS)
	@$(CC) $(FLAGS) -o $(NAME_PS) $(OBJ_PS) $(OBJ_OP) $(OBJ_ST) $(LIBFT)/libft.a

$(NAME_CH): $(OBJ_ST) $(OBJ_OP) $(OBJ_CH)
	@$(CC) $(FLAGS) -o $(NAME_CH) $(OBJ_CH) $(OBJ_OP) $(OBJ_ST) $(LIBFT)/libft.a

$(DIR_OBJS)/%.o: $(DIR_PS)/%.c
	@$(CC) $(FLAGS) -o $@ -c $<

$(DIR_OBJS)/%.o: $(DIR_CH)/%.c
	@$(CC) $(FLAGS) -o $@ -c $< 

$(DIR_OBJS)/%.o: $(DIR_OP)/%.c
	@$(CC) $(FLAGS) -o $@ -c $<

$(DIR_OBJS)/%.o: $(DIR_ST)/%.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ_CH) $(OBJ_PS) $(OBJ_OP) $(OBJ_ST)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME_CH) $(NAME_PS)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: fclean re all clean libft
