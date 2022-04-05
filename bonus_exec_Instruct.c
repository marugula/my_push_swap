/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_exec_Instruct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:51:53 by marugula          #+#    #+#             */
/*   Updated: 2022/03/10 16:16:27 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_of_instruct4(t_list **a, t_list **b, char *str)
{
	if (!ft_strncmp(str, "ra", 2))
	{
		rotate(a);
		return (1);
	}
	if (!ft_strncmp(str, "rb", 2))
	{
		rotate(b);
		return (1);
	}
	if (str[2] == '\n' || str[2] == 0)
	{
		if (!ft_strncmp(str, "rr", 2))
		{
			rotate(a);
			rotate(b);
			return (1);
		}
	}
	return (0);
}

int	exec_of_instruct3(t_list **a, t_list **b, char *str)
{
	if (!ft_strncmp(str, "pa", 2))
	{
		push(b, a);
		return (1);
	}
	if (!ft_strncmp(str, "pb", 2))
	{
		push(a, b);
		return (1);
	}
	return (exec_of_instruct4(a, b, str));
}

int	exec_of_instruct2(t_list **a, t_list **b, char *str)
{
	if (!ft_strncmp(str, "rra", 3))
	{
		rrotate(a);
		return (1);
	}
	if (!ft_strncmp(str, "rrb", 3))
	{
		rrotate(b);
		return (1);
	}
	if (!ft_strncmp(str, "rrr", 3))
	{
		rrotate(a);
		rrotate(b);
		return (1);
	}
	return (exec_of_instruct3(a, b, str));
}

int	exec_of_instruct(t_list **a, t_list **b, char *str)
{
	if (str == 0)
		return (0);
	if (ft_strlen(str) < 3 || ft_strlen(str) > 4)
		return (0);
	if (!ft_strncmp(str, "sa", 2))
	{
		swap(*a);
		return (1);
	}
	if (!ft_strncmp(str, "sb", 2))
	{
		swap(*b);
		return (1);
	}
	if (!ft_strncmp(str, "ss", 2))
	{
		swap(*a);
		swap(*b);
		return (1);
	}
	return (exec_of_instruct2(a, b, str));
}
