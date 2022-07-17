/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:11:13 by mmidon            #+#    #+#             */
/*   Updated: 2022/07/14 17:04:14 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_is_closed(char *map, int columns, int lines)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			i++;
		if (i <= columns + 1 && map[i] != '1')
			ft_error("not closed (1)");
		if (i >= (lines - 1) * (columns + 1) - 1 && map[i] != '1'
			&& i < (lines * columns) + pos(map, ft_strlen(map)))
		{
			ft_error("not closed (2)");
		}
		if (map[i] == '\0')
			return ;
		if (i >= columns + 1 && i < (lines - 1) * (columns + 1)
			&& map[i] != '1' && (map[i - 1] == '\n' || map[i + 1] == '\n'))
			ft_error("not closed (3)");
		i++;
	}
}

void	ft_check_char(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P'
			&& map[i] != 'C' && map[i] != 'E' && map[i] != 'X' && map[i] != '\n'
			&& map[i] != '\0')
			ft_error("invalid char in the map");
		i++;
	}
}

void	need_elements(char *test)
{
	if (test[1] + test[0] + test[2] + test[3] + test[4] == 0)
		ft_error("it's not a map");
	if (!test[1])
		ft_error("need wall plz");
	if (test[2] != 1)
		ft_error("need one player");
	if (!test[3])
		ft_error("need collectibles");
	if (!test[0])
		ft_error("need an exit");
}

void	ft_is_there_elements(char *map)
{
	char	*test;
	int		i;

	i = 0;
	test = malloc(sizeof(char) * 6);
	if (!test)
		return ;
	ft_bzero(test, 5);
	while (map[i])
	{
		if (map[i] == '1')
			test[1] = '1';
		if (map[i] == 'P')
			test[2]++;
		if (map[i] == 'C')
			test[3] = '1';
		if (map[i] == 'E')
			test[0] = '1';
		i++;
	}
	need_elements(test);
	free(test);
}

void	ft_check_map(t_mlx mlx, char *map)
{
	ft_check_char(map);
	ft_is_rectangular(map);
	ft_is_closed(map, mlx.map.columns, mlx.map.lines);
	ft_is_there_elements(map);
}
