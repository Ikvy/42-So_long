/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:16:50 by mmidon            #+#    #+#             */
/*   Updated: 2022/07/11 16:39:00 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *msg)
{
	ft_printf("Error : %s\n", msg);
	exit(1);
}

int	ft_strn(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i + 1);
}

void	ft_is_rectangular(char *map)
{
	int	i;
	int	tmp;

	i = 0;
	while (*map)
	{
		tmp = i;
		i = ft_strn(map);
		if (i != tmp && tmp)
			ft_error("the map isn't rectangular");
		map += i;
	}
}

int	do_open(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("can't open the map");
	return (fd);
}
