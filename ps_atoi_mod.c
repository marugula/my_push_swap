/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:31:37 by marugula          #+#    #+#             */
/*   Updated: 2022/03/09 13:24:56 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isaccept(char ch)
{
	if (ft_isdigit(ch) || ft_isspace(ch)
		|| ch == '+' || ch == '-' || ch == 0)
		return (1);
	else
		return (0);
}

int	num_size(int num)
{
	int	i;

	i = 1;
	while (num != 0)
	{
		num /= 10;
		if (num == 0)
			return (i);
		i++;
	}
	return (i);
}

int	pass_accept(char **str)
{
	int	minus;

	minus = 1;
	while (ft_isspace(**str) && **str != 0)
		(*str)++;
	if (!ft_isaccept(**str))
		ft_error("Forbidden characters\n", 0);
	if (**str == '-' || **str == '+')
	{
		if (!ft_isdigit(*(*str + 1)))
			ft_error("Forbidden characters\n", 0);
		if (**str == '-')
			minus *= -1;
		(*str)++;
	}
	while (**str == '0' && (*(*str + 1) != 0 || ft_isspace(*(*str + 1))))
		(*str)++;
	if (!ft_isaccept(**str))
		ft_error("Forbidden characters\n", 0);
	return (minus);
}

long long	math(char *str, int sign)
{
	long long	out;

	out = 0;
	while ((*str >= 48 && *str < 58))
	{
		out = out * 10 + (*str - 48);
		if (out * sign > 2147483647 || out * sign < -2147483648)
			ft_error("the number is not INT\n", 0);
		str++;
	}
	return (out);
}

int	ps_atoi_mod(char **str, int *num)
{
	int			sign;
	long long	n;

	sign = pass_accept(str);
	if (**str == 0)
		return (0);
	n = math(*str, sign) * sign;
	*num = n;
	*str += num_size(*num);
	return (1);
}
