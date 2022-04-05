/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rating_min_of_max.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:24:40 by marugula          #+#    #+#             */
/*   Updated: 2022/03/09 17:27:21 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ira_is_min_of_max(t_instruct *cmds)
{
	cmds->ir = cmds->irb;
	cmds->ira -= cmds->ir;
	cmds->irb = 0;
	cmds->irrb = 0;
	cmds->irra = 0;
}

void	irra_is_min_of_max(t_instruct *cmds)
{
	cmds->irr = cmds->irrb;
	cmds->irra -= cmds->irr;
	cmds->irrb = 0;
	cmds->ira = 0;
	cmds->irb = 0;
}

void	irrb_is_min_of_max(t_instruct *cmds)
{
	cmds->irr = cmds->irra;
	cmds->irrb -= cmds->irr;
	cmds->irra = 0;
	cmds->ira = 0;
	cmds->irb = 0;
}

void	irb_is_min_of_max(t_instruct *cmds)
{
	cmds->ir = cmds->ira;
	cmds->irb -= cmds->ir;
	cmds->ira = 0;
	cmds->irra = 0;
	cmds->irrb = 0;
}
