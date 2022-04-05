/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:24:19 by marugula          #+#    #+#             */
/*   Updated: 2022/03/09 17:26:04 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_norm_crutch
{
	int	i;
	int	pivot;
	int	k;
}	t_norm;

void	find_min_max(t_list *lst, int *min, int *max)
{
	t_list	*temp;

	temp = lst;
	*min = lst->num;
	*max = lst->num;
	while (lst->next != temp)
	{
		lst = lst->next;
		if (lst->num > *max)
			*max = lst->num;
		if (lst->num < *min)
			*min = lst->num;
	}
}

int	quick_select2(int buf[], int start, int end, t_norm s)
{
	int	temp;

	while (s.i != end)
	{
		if (buf[s.i] < buf[end])
		{
			temp = buf[s.i];
			buf[s.i] = buf[s.pivot];
			buf[s.pivot] = temp;
			s.pivot++;
		}
		s.i++;
	}
	temp = buf[end];
	buf[end] = buf[s.pivot];
	buf[s.pivot] = temp;
	if (s.pivot == s.k)
		return (buf[s.pivot]);
	else if (s.k < s.pivot)
		return (quick_select(buf, s.k, start, s.pivot));
	else
		return (quick_select(buf, s.k, s.pivot + 1, end));
}

int	quick_select(int buf[], int k, int start, int end)
{
	t_norm	s;

	if (start == end)
		return (buf[start]);
	s.pivot = start;
	s.i = start + 1;
	while (buf[s.pivot] < buf[end])
	{
		if (s.i == end)
		{
			if (k == end)
				return (buf[end]);
			return (quick_select(buf, k, start, end - 1));
		}
		s.pivot++;
		s.i++;
	}
	s.k = k;
	return (quick_select2(buf, start, end, s));
}

int	find_mid(t_list *lst)
{
	int		*buf;
	t_list	*temp;
	int		i;
	int		size;
	int		rez;

	size = size_stack(lst);
	temp = lst;
	buf = malloc(size * sizeof(int));
	if (buf == NULL)
		ft_error("malloc error", 1);
	i = 0;
	while (lst->next != temp)
	{
		buf[i++] = lst->num;
		lst = lst->next;
	}
	buf[i] = lst->num;
	rez = quick_select(buf, size / 2 - 1, 0, size - 1);
	free(buf);
	return (rez);
}
