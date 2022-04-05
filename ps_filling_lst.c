/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_filling_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:41:22 by marugula          #+#    #+#             */
/*   Updated: 2022/03/09 12:59:57 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int num)
{
	t_list	*lst;

	lst = ft_calloc(1, sizeof(*lst));
	if (lst == NULL)
		return (0);
	lst->num = num;
	lst->next = lst;
	lst->prev = lst;
	return (lst);
}

void	lst_free(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (lst != 0)
	{
		while (lst->next != temp)
		{
			lst = lst->next;
			free(lst->prev);
		}
	}
	free(lst);
}

void	lst_add_back(t_list *stack, t_list *new)
{
	t_list	*temp;

	if (new == 0)
	{
		lst_free(stack);
		ft_error("calloc error", 1);
	}
	temp = stack;
	while (stack->next != temp)
		stack = stack->next;
	stack->next = new;
	new->prev = stack;
	new->next = temp;
	temp->prev = new;
}

int	check_dup(t_list *lst, int n)
{
	t_list	*temp;

	temp = lst;
	while (lst->next != temp)
	{
		if (lst->num == n)
			ft_error("Enter duplicate number", 0);
		lst = lst->next;
	}
	if (lst->num == n)
		ft_error("Enter duplicate number", 0);
	return (n);
}

t_list	*lst_fill_num(int argc, char **argv)
{
	t_list	*lst;
	char	*str;
	int		i;
	int		num;

	i = 1;
	str = argv[i];
	if (ps_atoi_mod(&str, &num) == 0)
		str = argv[++i];
	lst = lst_new(num);
	while (i < argc)
	{
		if (i != 1)
			str = argv[i];
		while (1)
		{
			if (ps_atoi_mod(&str, &num) == 0)
				break ;
			lst_add_back(lst, lst_new(check_dup(lst, num)));
		}
		i++;
	}
	return (lst);
}
