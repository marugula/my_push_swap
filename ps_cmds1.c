/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmds1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:20:11 by marugula          #+#    #+#             */
/*   Updated: 2022/03/04 13:05:14 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_list **a, t_list **b)
{
	ft_putstr_fd("pa\n", 1);
	return (push(b, a));
}

int	pb(t_list **a, t_list **b)
{
	ft_putstr_fd("pb\n", 1);
	return (push(a, b));
}

void	ra(t_list **lst)
{
	ft_putstr_fd("ra\n", 1);
	rotate(lst);
}

void	rb(t_list **lst)
{
	ft_putstr_fd("rb\n", 1);
	rotate(lst);
}

void	rr(t_list **lst1, t_list **lst2)
{
	ft_putstr_fd("rr\n", 1);
	rotate(lst1);
	rotate(lst2);
}
