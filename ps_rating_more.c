/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rating_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:24:43 by marugula          #+#    #+#             */
/*   Updated: 2022/03/10 16:17:05 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ira_more_irb(t_instruct *cmds)
{
	if (cmds->irra > cmds->irrb)
	{
		if (cmds->ira < cmds->irra)
			ira_is_min_of_max(cmds);
		else
			irra_is_min_of_max(cmds);
	}
	else
	{
		if (cmds->ira < cmds->irrb)
			ira_is_min_of_max(cmds);
		else
			irrb_is_min_of_max(cmds);
	}
}

void	irb_more_ira(t_instruct *cmds)
{
	if (cmds->irra > cmds->irrb)
	{
		if (cmds->irb < cmds->irra)
			irb_is_min_of_max(cmds);
		else
			irra_is_min_of_max(cmds);
	}
	else
	{
		if (cmds->irb < cmds->irrb)
			irb_is_min_of_max(cmds);
		else
			irrb_is_min_of_max(cmds);
	}
}

void	fill_cmds(t_env *a, t_env *b)
{
	a->push = pb;
	a->rotate = ra;
	a->rrotate = rra;
	a->swap = sa;
	b->push = pa;
	b->rotate = rb;
	b->rrotate = rrb;
	b->swap = sb;
}
