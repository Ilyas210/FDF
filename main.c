/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:19:09 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/18 20:07:24 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error_message.h"
#include <libc.h>

void	ft_error(char *str, int errno)
{
	if (!errno)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	exit(1);
}

int	calc_width(char *line)
{
	int		i;
	char	**strs;

	i = 0;
	strs = ft_split(line, " \n");
	if (!strs)
	{
		free(line);
		return (0);
	}
	while (strs[i] && strs[i][0] != '\n')
		i++;
	free(line);
	free_split(strs);
	return (i);
}

void	get_width_height(t_fdf *fdf)
{
	char	*line;
	int		fd;

	fd = open(fdf->file, O_RDONLY);
	if (fd == -1)
		ft_error(ERR_OPEN_FILE, 0);
	line = get_next_line(fd);
	if (!line)
		return ;
	fdf->width = calc_width(line);
	while (line)
	{
		fdf->height++;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (fdf->width != calc_width(line))
		{
			fdf->height = 0;
			close(fd);
			return ;
		}
	}
	close(fd);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		return (ft_error(ERR_USAGE, 0), 1);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (ft_error(ERR_ALLOC_FAILED, 0), 1);
	init_map(fdf, av[1]);
	get_width_height(fdf);
	if (fdf->height == 0 || fdf->width == 0)
		return (free(fdf), ft_error(ERR_MAP_READING, 0), 1);
	intiate_zoom(fdf);
	fdf->points = fill_points(fdf);
	if (!fdf->points)
		return (free(fdf), ft_error("Failed to load points", 0), 1);
	initiate_mlx(fdf);
	black_window(fdf);
	draw_map(fdf, fdf->points);
	mlx_key_hook(fdf->mlx.mlx_ptr, key_hook, fdf);
	mlx_loop(fdf->mlx.mlx_ptr);
	mlx_terminate(fdf->mlx.mlx_ptr);
	free_fdf(fdf);
	return (0);
}
