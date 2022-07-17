/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:45:11 by mmidon            #+#    #+#             */
/*   Updated: 2022/07/17 07:44:24 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_data(char **map, t_player *player, char select, int direction)
{
	if (select == 'C')
	{
		player->atm_c++;
		select = '0';
	}
	else if (select == 'X')
	{
		player->pv--;
		if (player->pv == 0)
			ft_loose();
		return ;
	}
	(*map)[player->pos] = select;
	player->pos += direction;
	(*map)[player->pos] = 'P';
	++player->move;
}

void	update_enemy_sprite(t_mlx *mlx, int direction, size_t coor)
{
	size_t	x;
	size_t	y;
	int		i;
	int		j;

	y = coor + direction;
	x = coor;
	i = pos(mlx->map.strmap, coor) * mlx->map.img_height;
	j = (mlx->map.columns - plus(mlx->map.strmap + coor)) * mlx->map.img_width;
	open_everything(mlx, j, i, &x);
	j += mlx->map.img_width * direction;
	open_everything(mlx, j, i, &y);
}

void	update_enemy(t_mlx *mlx)
{
	size_t		pos;
	static int	zoui;

	if (!zoui)
		zoui = 1;
	pos = find_first_thing(mlx->map.strmap, 'X');
	while (pos && pos < ft_strlen(mlx->map.strmap))
	{
		if (mlx->map.strmap[pos + zoui] == '0')
		{
			mlx->map.strmap[pos] = '0';
			mlx->map.strmap[pos + zoui] = 'X';
		}
		else
			zoui *= -1;
		update_enemy_sprite(mlx, zoui, pos);
		pos = find_next_thing(mlx->map.strmap, pos + zoui, 'X');
	}
}

int	update_collectible(t_mlx *mlx)
{
	size_t			coords;
	int				i;
	int				j;

	if (!mlx->map.tempo)
		mlx->map.tempo = 0;
	coords = find_first_thing(mlx->map.strmap, 'C');
	while (coords && coords < ft_strlen(mlx->map.strmap))
	{
		i = pos(mlx->map.strmap, coords) * mlx->map.img_height;
		j = (mlx->map.columns - plus(mlx->map.strmap + coords))
			* mlx->map.img_width;
		open_image(FLOOR, mlx, &j, &i);
		open_everything(mlx, j, i, &coords);
		coords = find_next_thing(mlx->map.strmap, coords, 'C');
	}
	mlx->map.tempo++;
	return (0);
}

void	ft_move(t_player *player, int x, t_mlx *mlx)
{
	char	*zoui;

	if (mlx->map.strmap[player->pos + x] != '1')
	{
		if (mlx->map.strmap[player->pos + x] == 'C')
			update_data(&mlx->map.strmap, player, 'C', x);
		else if (mlx->map.strmap[player->pos + x] == 'E')
		{
			if (player->total_c == player->atm_c)
				ft_victory();
			else
				return ;
		}
		else if (mlx->map.strmap[player->pos + x] == 'X')
			update_data(&mlx->map.strmap, player, 'X', x);
		else if (mlx->map.strmap[player->pos + x] == '0')
			update_data(&mlx->map.strmap, player, '0', x);
		update_sprite(mlx, x);
		update_enemy(mlx);
		zoui = ft_itoa(mlx->player.move);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 11, 18, 255, zoui);
		free(zoui);
	}
}
