/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:45:35 by mmidon            #+#    #+#             */
/*   Updated: 2022/07/11 14:53:26 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_movement(int key, t_mlx *mlx)
{
	if (key == 0)
		ft_move(&mlx->player, -1, mlx);
	if (key == 2)
		ft_move(&mlx->player, 1, mlx);
	if (key == 1)
		ft_move(&mlx->player, mlx->map.columns + 1, mlx);
	if (key == 13)
		ft_move(&mlx->player, -mlx->map.columns - 1, mlx);
}

int	ft_close(void)
{
	exit(0);
}

int	key_handler(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(0);
	if ((key <= 2 && key >= 0) || key == 13)
	{
		ft_movement(key, mlx);
	}
	return (0);
}

void	hooking(t_mlx *mlx)
{
	mlx_hook(mlx->mlx_win, 17, 0, ft_close, 0);
	mlx_key_hook(mlx->mlx_win, key_handler, mlx);
}
