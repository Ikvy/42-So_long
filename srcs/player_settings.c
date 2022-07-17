/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:53:24 by mmidon            #+#    #+#             */
/*   Updated: 2022/07/07 07:31:52 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
#define PV 3

void	init_params(t_mlx *mlx)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (mlx->map.strmap[i])
	{
		if (mlx->map.strmap[i] == 'P')
			mlx->player.pos = i;
		if (mlx->map.strmap[i] == 'C')
			c++;
		i++;
	}
	mlx->player.total_c = c;
	mlx->player.pv = PV;
	mlx->player.atm_c = 0;
	mlx->player.move = 0;
}
