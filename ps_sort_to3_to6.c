/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_to3_to6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:27:28 by marugula          #+#    #+#             */
/*   Updated: 2022/03/09 17:34:17 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *lst)
{
	t_list	*temp;
	int		min;

	temp = lst;
	min = lst->num;
	while (lst->next != temp)
	{
		lst = lst->next;
		if (lst->num < min)
			min = lst->num;
	}
	return (min);
}

void	sort_to3_num(t_env *stack)
{
	if (is_sorted(stack->head) == FINAL_SORTED)
		return ;
	else if (is_sorted(stack->head) == PART_SORTED)
	{
		while (is_sorted(stack->head) != FINAL_SORTED)
			stack->rotate(&(stack->head));
		return ;
	}
	if (stack->head->num == find_min(stack->head))
		stack->rrotate(&(stack->head));
	else if (stack->head->prev->num == find_min(stack->head))
		stack->rotate(&(stack->head));
	stack->swap(stack->head);
	return ;
}

int	find_el_less_num(t_list *lst, int num)
{
	t_list	*temp;

	temp = lst;
	while (lst->next != temp)
	{
		if (num < lst->num)
			return (1);
		lst = lst->next;
	}
	if (num < lst->num)
		return (1);
	else
		return (0);
}

void	sort_to6_num_2(t_env *a, t_env *b)
{
	while (b->head != 0)
	{
		if (a->head->num > b->head->num
			|| (a->head->num == find_min(a->head) && b->head->next == b->head))
		{
			b->push(&(a->head), &(b->head));
			a->rotate(&(a->head));
		}
		else
		{
			a->rotate(&(a->head));
			if (find_el_less_num(a->head, b->head->num) == 0)
			{
				while (a->head->num != find_min(a->head))
					a->rotate(&(a->head));
				while (b->head != 0)
				{
					b->push(&(a->head), &(b->head));
					a->rotate(&(a->head));
				}
				break ;
			}
		}
	}
}

void	sort_to6_num(t_env *a, t_env *b)
{
	int	size;

	size = size_stack(a->head);
	if (size % 2 == 1)
		size = size / 2 + 1;
	else
		size /= 2;
	while (size_stack(a->head) > size)
		a->push(&(a->head), &(b->head));
	sort_to3_num(a);
	sort_to3_num(b);
	if (a->head->prev->num < b->head->num)
	{
		while (b->head != 0)
		{
			b->push(&(a->head), &(b->head));
			a->rotate(&(a->head));
		}
		return ;
	}
	sort_to6_num_2(a, b);
	while (is_sorted(a->head) != FINAL_SORTED)
		a->rotate(&(a->head));
}
