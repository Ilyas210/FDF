/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:26:15 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/19 00:44:11 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error_message.h"

void	isometric(t_fdf *fdf, t_point *points)
{
	int		i;
	float	prev_x;

	i = 0;
	prev_x = points->x;
	points->z /= 10;
	points->z *= fdf->z_move;
	points->x = (points->x - points->y) * cos(fdf->angle);
	points->y = (prev_x + points->y) * sin(fdf->angle) - points->z;
}

void	change_points(t_fdf *fdf, t_point *p1, t_point *p2)
{
	if (fdf->iso)
	{
		isometric(fdf, p1);
		isometric(fdf, p2);
	}
	if (fdf->zoom < 0)
		fdf->zoom = 0;
	if (fdf->zoom > 5000)
		fdf->zoom = 5000;
	p1->x = p1->x * fdf->zoom + fdf->x_move;
	p1->y = p1->y * fdf->zoom + fdf->y_move;
	p2->x = p2->x * fdf->zoom + fdf->x_move;
	p2->y = p2->y * fdf->zoom + fdf->y_move;
}

void	draw_line_dda(t_fdf *fdf, t_point p1, t_point p2)
{
	float	x_step;
	float	y_step;
	float	max;
	int		i;

	i = 0;
	change_points(fdf, &p1, &p2);
	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;
	if (fabs(x_step) > fabs(y_step))
		max = fabs(x_step);
	else
		max = fabs(y_step);
	x_step /= max;
	y_step /= max;
	while (i <= (int)max)
	{
		if (p1.x >= 0 && p1.y >= 0
			&& p1.x < fdf->win_width && p1.y < fdf->win_height)
			mlx_put_pixel(fdf->mlx.img, (int)p1.x,
				(int)p1.y, get_color(p1, p2, i / (float)max));
		p1.x += x_step;
		p1.y += y_step;
		i++;
	}
}

void	draw_map(t_fdf *fdf, t_point **points)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf->height)
	{
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				draw_line_dda(fdf, points[y][x], points[y][x + 1]);
			if (y < fdf->height - 1)
				draw_line_dda(fdf, points[y][x], points[y + 1][x]);
			x++;
		}
		y++;
		x = 0;
	}
}

void	redraw_map(t_fdf *fdf, t_point **points)
{
	mlx_delete_image(fdf->mlx.mlx_ptr, fdf->mlx.img);
	fdf->mlx.img
		= mlx_new_image(fdf->mlx.mlx_ptr, fdf->win_width, fdf->win_height);
	if (!fdf->mlx.img
		|| mlx_image_to_window(fdf->mlx.mlx_ptr, fdf->mlx.img, 0, 0) < 0)
	{
		free_fdf(fdf);
		ft_error(ERR_FDF_INIT, 1);
	}
	black_window(fdf);
	draw_map(fdf, points);
}
