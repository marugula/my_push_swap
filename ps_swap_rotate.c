/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:14:38 by marugula          #+#    #+#             */
/*   Updated: 2022/03/10 13:42:13 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *lst)
{
	ft_putstr_fd("sa\n", 1);
	swap(lst);
}

void	sb(t_list *lst)
{
	ft_putstr_fd("sb\n", 1);
	swap(lst);
}

void	swap(t_list *lst)
{
	int	temp;

	if (lst == 0)
		return ;
	temp = lst->num;
	lst->num = lst->next->num;
	lst->next->num = temp;
}

void	rotate(t_list **lst)
{
	if (*lst == 0)
		return ;
	*lst = (*lst)->next;
}

void	rrotate(t_list **lst)
{
	if (*lst == 0)
		return ;
	*lst = (*lst)->prev;
}
