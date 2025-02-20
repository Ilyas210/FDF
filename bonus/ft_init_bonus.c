/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:41:01 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/20 01:39:24 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../error_message.h"

void	check_file(t_fdf *fdf)
{
	char	*found;

	found = ft_strchr(fdf->file, '.');
	if (!found)
	{
		free(fdf);
		ft_error(ERR_OPEN_FILE);
	}
	found = ft_strchr(found + 1, '.');
	if (found)
	{
		free(fdf);
		ft_error(ERR_OPEN_FILE);
	}
}

void	init_map(t_fdf *fdf, char *file_path)
{
	fdf->file = file_path;
	fdf->win_height = 2000;
	fdf->win_width = 2000;
	fdf->height = 0;
	fdf->width = 0;
	fdf->zoom = 2;
	fdf->iso = 1;
	fdf->angle = 30;
	fdf->x_move = 800;
	fdf->y_move = 300;
	fdf->z_move = 1;
	fdf->points = NULL;
	fdf->bonus = 1;
	fdf->signe = 0;
	check_file(fdf);
}

void	intiate_zoom(t_fdf *fdf)
{
	if (fdf->width < 50)
		fdf->zoom = 30;
	else if (fdf->width < 500)
		fdf->zoom = 3;
	else
		fdf->zoom = 1;
}

void	initiate_mlx(t_fdf *fdf)
{
	fdf->mlx.mlx_ptr = mlx_init(fdf->win_width, fdf->win_height, "FDF", 1);
	if (!fdf->mlx.mlx_ptr)
	{
		free_fdf(fdf);
		ft_error(ERR_FDF_INIT);
	}
	fdf->mlx.img
		= mlx_new_image(fdf->mlx.mlx_ptr, fdf->win_width, fdf->win_height);
	if (!fdf->mlx.img
		|| mlx_image_to_window(fdf->mlx.mlx_ptr, fdf->mlx.img, 0, 0) < 0)
	{
		free_fdf(fdf);
		ft_error(ERR_FDF_INIT);
	}
}
