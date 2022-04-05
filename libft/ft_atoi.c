/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:10:24 by marugula          #+#    #+#             */
/*   Updated: 2022/01/22 18:43:37 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char ch)
{
	if (ch == '\t' || ch == '\v' || ch == '\f'
		|| ch == '\r' || ch == '\n' || ch == ' ')
		return (1);
	return (0);
}

static long long	math(char *str, int minus)
{
	long long	out;

	out = 0;
	while ((*str >= 48 && *str < 58))
	{
		out = out * 10 + (*str - 48);
		str++;
	}
	return (out * minus);
}

long long	ft_atoi(const char *nptr)
{
	char		*s;
	int			minus;

	s = (char *)nptr;
	minus = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
	{
		s++;
		minus *= -1;
	}
	else if (*s == '+')
		s++;
	return (math(s, minus));
}

/*int main(int argv, char **argc)
{
	printf("%d\n", atoi(argc[1]));
	printf("%d\n", ft_atoi(argc[1]));   
}*/
