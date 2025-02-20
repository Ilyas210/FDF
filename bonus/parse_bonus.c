/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:59:05 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/20 01:39:41 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../error_message.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[i] == ',')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] != ',')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	fill_color(char *comma, int z_val, unsigned int *color)
{
	int	num;

	num = 0;
	if (comma)
	{
		num = ft_atoi_base(comma + 1, 16);
		if (num == -1)
			return (0);
		*color = num << 8 | 0xFF;
	}
	else if (z_val)
		*color = 0x00FF00FF;
	else
		*color = 0xFF0000FF;
	return (1);
}

int	parse(char *line, t_point **points, int n)
{
	char	**strs;
	int		i;
	char	*comma;

	i = 0;
	if (!line)
		return (0);
	strs = ft_split(line, " \n");
	if (!strs)
		return (free(line), 0);
	while (strs[i])
	{
		if (!is_number(strs[i]))
			return (free_split(strs), free(line), 0);
		points[n][i].y = n;
		points[n][i].x = i;
		points[n][i].z = ft_atoi(strs[i]);
		comma = ft_strchr(strs[i], ',');
		if (!fill_color(comma, points[n][i].z, &points[n][i].color))
			return (free_split(strs), free(line), 0);
		i++;
	}
	return (free_split(strs), free(line), 1);
}

t_point	**fill_points(t_fdf *fdf)
{
	t_point	**points;
	int		i;
	int		j;
	int		fd;

	fd = open(fdf->file, O_RDONLY);
	if (fd == -1)
		return (free(fdf), ft_error(ERR_OPEN_FILE), NULL);
	points = malloc(fdf->height * sizeof(t_point *));
	if (!points)
		return (close(fd), NULL);
	i = 0;
	j = 0;
	while (i < fdf->height)
	{
		points[i] = malloc(fdf->width * sizeof(t_point));
		if (!points[i])
			return (close(fd), free_points(points, i), NULL);
		if (!parse(get_next_line(fd), points, i))
			return (close(fd), free_points(points, i + 1), NULL);
		i++;
	}
	return (get_next_line(fd), close(fd), points);
}
