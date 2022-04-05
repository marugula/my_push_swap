/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:24:46 by marugula          #+#    #+#             */
/*   Updated: 2022/03/09 17:31:02 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_cmds(t_instruct *cmds)
{
	cmds->ir = 0;
	cmds->irr = 0;
	cmds->ira = 0;
	cmds->irb = 0;
	cmds->irra = 0;
	cmds->irrb = 0;
}

void	count_cmd_for_rotate(t_list *a, t_list *b, t_list *el, t_instruct *cmds)
{
	t_list	*temp;
	int		min;
	int		max;

	temp = b;
	find_min_max(a, &min, &max);
	while (temp != el)
	{
		rotate(&temp);
		cmds->irb++;
	}
	temp = a;
	while (!(temp->num > el->num && temp->prev->num < el->num))
	{
		rotate(&temp);
		if (cmds->ira != 0 && temp->num == max && temp->prev->num == min)
		{
			rotate(&temp);
			cmds->ira++;
		}
		cmds->ira++;
	}
}

void	count_cmd_for_rrotate(t_list *a, t_list *b,
							t_list *el, t_instruct *cmds)
{
	t_list	*temp;
	int		min;
	int		max;

	temp = b;
	find_min_max(a, &min, &max);
	while (temp != el)
	{
		rrotate(&temp);
		cmds->irrb++;
	}
	temp = a;
	while (!(temp->num > el->num && temp->prev->num < el->num))
	{
		rrotate(&temp);
		if (cmds->irra != 0 && temp->num == max && temp->prev->num == min)
		{
			rrotate(&temp);
			cmds->irra++;
		}
		cmds->irra++;
	}
}

int	el_raiting(t_list *a, t_list *b, t_list *el, t_instruct *cmds)
{
	clear_cmds(cmds);
	count_cmd_for_rotate(a, b, el, cmds);
	count_cmd_for_rrotate(a, b, el, cmds);
	if (cmds->ira > cmds->irb)
		ira_more_irb(cmds);
	else
		irb_more_ira(cmds);
	return (cmds->ir + cmds->irr + \
			cmds->ira + cmds->irra + \
			cmds->irb + cmds->irrb);
}

int	better_el_in_stack(t_env a, t_env b, t_instruct *cmds)
{
	t_list		*temp;
	t_instruct	temp_cmds;
	int			min_rat;
	int			rat;

	temp = b.head;
	temp_cmds = *cmds;
	clear_cmds(&temp_cmds);
	rat = el_raiting(a.head, b.head, temp, &temp_cmds);
	min_rat = rat;
	*cmds = temp_cmds;
	temp = temp->next;
	while (temp != b.head)
	{
		rat = el_raiting(a.head, b.head, temp, &temp_cmds);
		if (min_rat > rat)
		{
			min_rat = rat;
			*cmds = temp_cmds;
		}
		temp = temp->next;
	}
	return (min_rat);
}
