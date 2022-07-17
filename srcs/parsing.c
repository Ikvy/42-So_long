/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:13:34 by mmidon            #+#    #+#             */
/*   Updated: 2022/07/17 08:34:53 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	strline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

void	set_dimensions(t_mlx *mlx, char *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	mlx->map.columns = strline(map);
	while (map[j])
	{
		if (map[j++] == '\n')
			i++;
	}
	mlx->map.lines = i;
}

void	good_map(char *av)
{
	int	x;
	int	i;

	x = ft_strlen(av);
	if (x <= 4)
		ft_error("need a real map");
	i = x;
	while (av[i] != '/')
		i--;
	if ((x <= 4 && av[x - 5] == '/') || ft_strlen(av + i + 1) <= 4)
		ft_error("need a real map");
	if (av[x - 1] != 'r' || av[x - 2] != 'e'
		|| av[x - 3] != 'b' || av[x - 4] != '.')
		ft_error("need a \".ber\" map");
}

void	vs_code_de_ses_morts(char *map)
{
	int	x;

	x = ft_strlen(map);
	if (x)
	{
		if (map[x - 1] != '\n')
		{
			map[x] = '\n';
			map[x + 1] = '\0';
		}
	}
}

char	*get_map(char *av, t_mlx *mlx)
{
	int		fd;
	int		loop;
	char	*tmp;
	char	*map;

	good_map(av);
	loop = 0;
	fd = do_open(av);
	tmp = ft_strdup("");
	map = ft_strdup("");
	while (tmp != NULL && ++loop)
	{
		if (loop == 1)
			free(tmp);
		tmp = get_next_line(fd);
		map = ft_strjoin(map, tmp);
	}
	vs_code_de_ses_morts(map);
	set_dimensions(mlx, map);
	ft_check_map(*mlx, map);
	return (map);
}
