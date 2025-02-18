/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:22:46 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/18 17:05:57 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	black_window(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf->win_height)
	{
		x = 0;
		while (x < fdf->win_width)
			mlx_put_pixel(fdf->mlx.img, x++, y, 0x000000FF);
		y++;
	}
}
