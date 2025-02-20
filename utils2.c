/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:27:39 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/20 01:36:42 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error_message.h"

void	chech_open_file(t_fdf *fdf, int *fd)
{
	*fd = open(fdf->file, O_RDONLY);
	if (*fd == -1)
	{
		free(fdf);
		ft_error(ERR_OPEN_FILE);
	}
}

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
