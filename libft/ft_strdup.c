/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:54:24 by marugula          #+#    #+#             */
/*   Updated: 2021/10/11 16:54:26 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	int		i;
	char	*new;

	i = 0;
	size = ft_strlen(s);
	new = malloc(size * sizeof(char) + 1);
	if (new == 0)
	{
		return (0);
	}
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*int main(int argv, char **argc)
{
	char *ptr = ft_strdup(argc[1]);
	free(ptr);
}*/
