/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:54:54 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/15 21:58:36 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if ((keydata.key == 122 || keydata.key == 90)
		&& keydata.action == MLX_PRESS)
		fdf->iso = !fdf->iso;
	if (keydata.key == 256 && keydata.action == MLX_PRESS)
		mlx_clear(fdf);
	redraw_map(fdf, fdf->points);
}
