/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:00:03 by mmidon            #+#    #+#             */
/*   Updated: 2022/07/17 07:44:49 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_anim(t_mlx *mlx)
{
	int		img_width;
	int		img_height;
	void	**tmp;

	tmp = malloc(sizeof(void *) * 9);
	tmp[0] = mlx_xpm_file_to_image(mlx->mlx,
			"./images/collectible/Leaf_Dude1.xpm", &img_width, &img_height);
	tmp[1] = mlx_xpm_file_to_image(mlx->mlx,
			"./images/collectible/Leaf_Dude2.xpm", &img_width, &img_height);
	tmp[2] = mlx_xpm_file_to_image(mlx->mlx,
			"./images/collectible/Leaf_Dude3.xpm", &img_width, &img_height);
	tmp[3] = mlx_xpm_file_to_image(mlx->mlx,
			"./images/collectible/Leaf_Dude4.xpm", &img_width, &img_height);
	tmp[4] = mlx_xpm_file_to_image(mlx->mlx,
			"./images/collectible/Leaf_Dude5.xpm", &img_width, &img_height);
	tmp[5] = mlx_xpm_file_to_image(mlx->mlx,
			"./images/collectible/Leaf_Dude6.xpm", &img_width, &img_height);
	tmp[6] = mlx_xpm_file_to_image(mlx->mlx,
			"./images/collectible/Leaf_Dude7.xpm", &img_width, &img_height);
	tmp[7] = mlx_xpm_file_to_image(mlx->mlx,
			"./images/collectible/Leaf_Dude8.xpm", &img_width, &img_height);
	tmp[8] = NULL;
	mlx->map.anim = tmp;
}

void	open_anim(t_mlx *mlx, int *i, int *j)
{
	size_t	x;

	x = mlx->map.tempo / 10;
	if (x >= 8)
	{
		x = 0;
		mlx->map.tempo = 0;
	}
	if (!mlx->map.anim[x])
		ft_error("problem with textures");
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->map.anim[x], *i, *j);
}

void	open_image(char *path_to_file, t_mlx *mlx, int *i, int *j)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx->mlx, path_to_file,
			&img_width, &img_height);
	if (!img)
		ft_error("problem with textures");
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, *i, *j);
}
