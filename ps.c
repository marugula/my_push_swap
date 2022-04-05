/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:45:34 by marugula          #+#    #+#             */
/*   Updated: 2022/03/10 17:08:50 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_in_b(t_env *a, t_env *b)
{
	int	mid;
	int	min;
	int	max;

	mid = find_mid(a->head);
	find_min_max(a->head, &min, &max);
	while (size_stack(a->head) != 2)
	{
		if (a->head->num != min && a->head->num != max)
		{
			a->push(&(a->head), &(b->head));
			if (b->head->num > mid)
				b->rotate(&(b->head));
		}
		else
			a->rotate(&(a->head));
	}
}

void	sort_all(t_env *a, t_env *b)
{
	t_instruct	cmds;

	push_all_in_b(a, b);
	clear_cmds(&cmds);
	while (size_stack(b->head) != 0)
	{
		clear_cmds(&cmds);
		better_el_in_stack(*a, *b, &cmds);
		find_pozition(a, b, cmds);
		b->push(&(a->head), &(b->head));
	}
}

int	main(int argc, char **argv)
{
	t_env	a;
	t_env	b;

	if (argc < 2)
		return (0);
	exit(0);
	a.head = lst_fill_num(argc, argv);
	b.head = NULL;
	lst_print_content(a.head, "stack a:\n\n");
	fill_cmds(&a, &b);
	if (is_sorted(a.head) != FINAL_SORTED)
	{
		if (size_stack(a.head) <= 3)
			sort_to3_num(&a);
		else if (size_stack(a.head) <= 6)
			sort_to6_num(&a, &b);
		else
			sort_all(&a, &b);
	}
	if (is_sorted(a.head) == PART_SORTED)
	{
		while (is_sorted(a.head) != FINAL_SORTED)
			a.rotate(&(a.head));
	}
	lst_free(a.head);
}
