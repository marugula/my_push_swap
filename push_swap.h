/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:45:38 by marugula          #+#    #+#             */
/*   Updated: 2022/03/10 12:56:08 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>

# define FINAL_SORTED 1
# define PART_SORTED 0
# define NOT_SORTED -1
# define EMPTY_STACK -2

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_stackenv
{
	t_list	*head;
	void	(*swap)(t_list *);
	void	(*rotate)(t_list **);
	void	(*rrotate)(t_list **);
	int		(*push)(t_list **, t_list **);
}	t_env;

typedef struct count_instructions
{
	int	ira;
	int	irb;
	int	irra;
	int	irrb;
	int	ir;
	int	irr;
}	t_instruct;

/* ps_filling_lst.c */
t_list	*lst_fill_num(int argc, char **argv);
void	lst_free(t_list *lst);

/* ps_sort_to3_to6.c */
void	sort_to3_num(t_env *stack);
void	sort_to6_num(t_env *a, t_env *b);

/* ps_utils.c */
int		lst_print_content(t_list *lst, char *str);
void	ft_error(char *str, int codeerr);
void	fill_cmds(t_env *a, t_env *b);
int		is_sorted(t_list *lst);
int		size_stack(t_list *lst);

/* ps_atoi_mod.c */
int		ps_atoi_mod(char **str, int *num);

/* ps_push.c */
int		push(t_list	**src, t_list **dest);

/* ps_swap_rotate.c */
void	rrotate(t_list **lst);
void	rotate(t_list **lst);
void	swap(t_list *lst);
void	sb(t_list *lst);
void	sa(t_list *lst);

/* ps_cmds1.c */
void	rr(t_list **lst1, t_list **lst2);
void	rb(t_list **lst);
void	ra(t_list **lst);
int		pb(t_list **a, t_list **b);
int		pa(t_list **a, t_list **b);

/* ps_cmds2.c */
void	ss(t_list *lst1, t_list *lst2);
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **lst1, t_list **lst2);

/* ps_find_mid.c */
int		find_mid(t_list *lst);
void	find_min_max(t_list *lst, int *min, int *max);

/* ps_find_pozition.c */
void	find_pozition(t_env *a, t_env *b, t_instruct cmds);
int		quick_select(int buf[], int k, int start, int end);

/* ps_rating.c */
int		better_el_in_stack(t_env a, t_env b, t_instruct *cmds);
void	clear_cmds(t_instruct *cmds);

/* ps_rating_more.c */
void	irb_more_ira(t_instruct *cmds);
void	ira_more_irb(t_instruct *cmds);

/* ps_rating_min_of_max.c */
void	ira_is_min_of_max(t_instruct *cmds);
void	irra_is_min_of_max(t_instruct *cmds);
void	irrb_is_min_of_max(t_instruct *cmds);
void	irb_is_min_of_max(t_instruct *cmds);

#endif