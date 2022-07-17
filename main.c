/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:53:23 by mmidon            #+#    #+#             */
/*   Updated: 2022/07/15 14:35:31 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		ft_error("Need one map");
	mlx.map.strmap = get_map(av[1], &mlx);
	mlx.mlx = mlx_init();
	mlx.map.img_height = 0;
	mlx.map.img_width = 0;
	mlx_xpm_file_to_image (mlx.mlx, FLOOR, &mlx.map.img_height,
		&mlx.map.img_width);
	if (mlx.map.img_height == 0 || mlx.map.img_width == 0)
		ft_error("there's a lot of reasons why you should not do that");
	mlx.mlx_win = mlx_new_window(mlx.mlx, mlx.map.columns
			* mlx.map.img_height, mlx.map.lines * mlx.map.img_width, "so_long");
	set_anim(&mlx);
	set_the_prettiest_thing_you_ve_ever_seen(&mlx);
	init_params(&mlx);
	mlx_loop_hook(mlx.mlx, update_collectible, &mlx);
	hooking(&mlx);
	mlx_loop(mlx.mlx);
}
