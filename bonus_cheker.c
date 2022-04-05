/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cheker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:58:35 by marugula          #+#    #+#             */
/*   Updated: 2022/03/10 16:12:12 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_of_instruct(t_list **a, t_list **b, char *str);

int	read_exec_of_instruct(t_list **a, t_list **b)
{
	char	*str;
	int		error_code;

	error_code = 0;
	str = get_next_line(STDIN_FILENO, &error_code);
	if (error_code == -1)
		return (-1);
	if (str == 0)
		return (0);
	free(str);
	if (exec_of_instruct(a, b, str) == 0)
		return (-1);
	return (1);
}

void	ft_exit(char *mesg, t_list *a, t_list *b, int fd)
{
	if (a != 0)
		lst_free(a);
	if (b != 0)
		lst_free(b);
	if (mesg != 0)
		ft_putstr_fd(mesg, fd);
	if (fd == STDERR_FILENO)
		exit(0);
	else
		exit (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		exec_code;

	if (argc == 1)
		return (0);
	a = lst_fill_num(argc, argv);
	b = 0;
	while (1)
	{
		exec_code = read_exec_of_instruct(&a, &b);
		if (exec_code == -1)
			ft_exit("Error\n", a, b, STDERR_FILENO);
		if (exec_code == 0)
		{
			if (is_sorted(a) == FINAL_SORTED)
				ft_exit("OK\n", a, b, STDOUT_FILENO);
			else
				ft_exit("KO\n", a, b, STDOUT_FILENO);
		}
	}
}
