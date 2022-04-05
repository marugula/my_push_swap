/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:26:46 by marugula          #+#    #+#             */
/*   Updated: 2022/03/10 16:17:21 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_stack(t_list *lst)
{
	t_list	*temp;
	int		i;

	if (lst == NULL)
		return (0);
	i = 1;
	temp = lst;
	while (lst->next != temp)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	is_sorted(t_list *lst)
{
	t_list	*temp;

	if (lst == 0)
		return (EMPTY_STACK);
	temp = lst;
	while (lst->next->num > lst->num)
		lst = lst->next;
	lst = lst->next;
	if (lst == temp)
		return (FINAL_SORTED);
	temp = lst;
	while (lst->next->num > lst->num)
		lst = lst->next;
	if (lst->next == temp)
		return (PART_SORTED);
	return (NOT_SORTED);
}

void	ft_error(char *str, int codeerr)
{
	ft_putstr_fd("Error\n", 2);
	if (codeerr == 0 && str != 0)
	{
		exit(0);
	}
	else
	{
		perror(str);
		exit(0);
	}
}

int	lst_print_content(t_list *lst, char *str)
{
	t_list	*temp;

	printf("%s", str);
	if (lst == 0)
	{
		printf("(null)\n");
		return (-1);
	}
	temp = lst;
	while (lst->next != temp)
	{
		printf("%d\n", lst->num);
		lst = lst->next;
	}
	printf("%d\n", lst->num);
	return (0);
}
