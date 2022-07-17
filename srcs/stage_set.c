/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:28:53 by mmidon            #+#    #+#             */
/*   Updated: 2022/07/17 07:33:37 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_everything(t_mlx *mlx, int j, int i, size_t *map)
{
	open_image(FLOOR, mlx, &j, &i);
	if (mlx->map.strmap[*map] == '\n')
		(*map)++;
	if (mlx->map.strmap[*map] == '1')
		open_image(WALL, mlx, &j, &i);
	if (mlx->map.strmap[*map] == 'P')
		open_image(PJ, mlx, &j, &i);
	if (mlx->map.strmap[*map] == 'E')
		open_image(ESCAPE, mlx, &j, &i);
	if (mlx->map.strmap[*map] == 'C')
		open_anim(mlx, &j, &i);
	if (mlx->map.strmap[*map] == 'X')
		open_image(ENEMY, mlx, &j, &i);
}

void	set_the_prettiest_thing_you_ve_ever_seen(t_mlx *mlx)
{
	int		i;
	int		j;
	size_t	map;

	i = 0;
	map = 0;
	while (i <= mlx->map.lines * mlx->map.img_width
		&& i / mlx->map.img_height < mlx->map.lines
		&& mlx->map.strmap[map])
	{
		j = 0;
		while (j <= mlx->map.columns * mlx->map.img_height
			&& j / mlx->map.img_width < mlx->map.columns
			&& mlx->map.strmap[map])
		{
			open_everything(mlx, j, i, &map);
			j += mlx->map.img_width;
			map++;
		}
		i += mlx->map.img_height;
	}
}

int	plus(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

int	pos(char *str, int pos)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i != pos && str[i])
	{
		if (str[i] == '\n')
			x++;
		i++;
	}
	return (x);
}

void	update_sprite(t_mlx *mlx, int direction)
{
	int		j;
	int		i;
	size_t	x;
	size_t	y;

	i = 0;
	j = 0;
	open_image(WALL, mlx, &i, &j);
	y = (size_t)mlx->player.pos - direction;
	x = (size_t)mlx->player.pos;
	i = pos(mlx->map.strmap, mlx->player.pos) * mlx->map.img_height;
	j = (mlx->map.columns - plus(mlx->map.strmap + mlx->player.pos))
		* mlx->map.img_width;
	open_everything(mlx, j, i, &x);
	if (direction == -1 || direction == 1)
		j -= mlx->map.img_width * direction;
	else if (direction == mlx->map.columns + 1)
		i -= mlx->map.img_height;
	else if (direction == -mlx->map.columns - 1)
		i += mlx->map.img_height;
	open_everything(mlx, j, i, &y);
}
