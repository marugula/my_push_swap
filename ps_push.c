/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:42:08 by marugula          #+#    #+#             */
/*   Updated: 2022/03/09 17:40:56 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*pop_from(t_list **src)
{
	t_list	*elem;

	elem = *src;
	if (*src == (*src)->next)
		*src = 0;
	else
	{
		(*src)->next->prev = (*src)->prev;
		(*src)->prev->next = (*src)->next;
		*src = (*src)->next;
	}
	elem->next = elem;
	elem->prev = elem;
	return (elem);
}

void	push_in(t_list *elem, t_list **dest)
{
	t_list	*last;

	if (*dest != 0)
	{
		if (*dest == (*dest)->next)
		{
			(*dest)->prev = elem;
			(*dest)->next = elem;
			elem->next = (*dest);
			elem->prev = (*dest);
		}
		else
		{
			last = (*dest)->prev;
			last->next = elem;
			(*dest)->prev = elem;
			elem->prev = last;
			elem->next = (*dest);
		}
	}
	*dest = elem;
}

int	push(t_list	**src, t_list **dest)
{
	if (*src == 0)
		return (EMPTY_STACK);
	push_in(pop_from(src), dest);
	return (0);
}
