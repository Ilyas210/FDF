/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:52:45 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/20 22:16:04 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	move_coordinates(mlx_key_data_t keydata, t_fdf	*fdf)
{
	if (keydata.key == 262 && keydata.action == MLX_PRESS)
		fdf->x_move += 20;
	if (keydata.key == 263 && keydata.action == MLX_PRESS)
		fdf->x_move -= 20;
	if (keydata.key == 264 && keydata.action == MLX_PRESS)
		fdf->y_move += 20;
	if (keydata.key == 265 && keydata.action == MLX_PRESS)
		fdf->y_move -= 20;
	if (keydata.key == 322 && keydata.action == MLX_PRESS)
		fdf->z_move -= 1;
	if (keydata.key == 328 && keydata.action == MLX_PRESS)
		fdf->z_move += 1;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keydata.key == 61 && keydata.action == MLX_PRESS)
		fdf->zoom += 1;
	if (keydata.key == 45 && keydata.action == MLX_PRESS)
		fdf->zoom -= 1;
	if ((keydata.key == 122 || keydata.key == 90)
		&& keydata.action == MLX_PRESS)
		fdf->iso = !fdf->iso;
	if (keydata.key == 256 && keydata.action == MLX_PRESS)
		mlx_clear(fdf);
	if (keydata.key == 82 && keydata.action == MLX_PRESS && fdf->iso)
		fdf->angle += 1;
	if (keydata.key == 80 && keydata.action == MLX_PRESS && fdf->iso)
		fdf->angle -= 1;
	move_coordinates(keydata, fdf);
	redraw_map(fdf, fdf->points);
}
