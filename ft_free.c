/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:17:44 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/18 20:07:19 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	free_all(char **strs, char *line)
{
	free_split(strs);
	if (line)
		free(line);
}

void	free_points(t_point **points, int height)
{
	int	i;

	if (!points)
		return ;
	i = 0;
	while (i < height)
		free(points[i++]);
	free(points);
	points = NULL;
}

void	free_fdf(t_fdf *fdf)
{
	if (!fdf)
		return ;
	free_points(fdf->points, fdf->height);
	free(fdf);
}

void	mlx_clear(t_fdf *fdf)
{
	mlx_terminate(fdf->mlx.mlx_ptr);
	free_fdf(fdf);
	exit(1);
}
