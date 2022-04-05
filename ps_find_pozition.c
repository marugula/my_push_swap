/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_pozition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:24:28 by marugula          #+#    #+#             */
/*   Updated: 2022/03/09 17:26:42 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pozition2(t_env *a, t_env *b, t_instruct cmds)
{
	while (cmds.ir != 0)
	{
		rr(&(a->head), &(b->head));
		(cmds.ir)--;
	}
	while (cmds.irr != 0)
	{
		rrr(&(a->head), &(b->head));
		(cmds.irr)--;
	}
	while (cmds.ira != 0)
	{
		ra(&(a->head));
		(cmds.ira)--;
	}
}

void	find_pozition(t_env *a, t_env *b, t_instruct cmds)
{
	while (cmds.irb != 0)
	{
		rb(&(b->head));
		(cmds.irb)--;
	}
	while (cmds.irra != 0)
	{
		rra(&(a->head));
		(cmds.irra)--;
	}
	while (cmds.irrb != 0)
	{
		rrb(&(b->head));
		(cmds.irrb)--;
	}
	find_pozition2(a, b, cmds);
}
