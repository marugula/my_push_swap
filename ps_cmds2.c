/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmds2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:33:02 by marugula          #+#    #+#             */
/*   Updated: 2022/03/04 13:04:34 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list *lst1, t_list *lst2)
{
	ft_putstr_fd("ss\n", 1);
	swap(lst1);
	swap(lst2);
}

void	rra(t_list **lst)
{
	ft_putstr_fd("rra\n", 1);
	rrotate(lst);
}

void	rrb(t_list **lst)
{
	ft_putstr_fd("rrb\n", 1);
	rrotate(lst);
}

void	rrr(t_list **lst1, t_list **lst2)
{
	ft_putstr_fd("rrr\n", 1);
	rrotate(lst1);
	rrotate(lst2);
}
