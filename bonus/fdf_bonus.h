/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:21:46 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/20 01:52:06 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include <unistd.h>
# include "../MLX42.h"
# include <math.h>
# include <limits.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_point
{
	float			x;
	float			y;
	float			z;
	unsigned int	color;
}					t_point;

typedef struct s_mlx
{
	mlx_t		*mlx_ptr;
	mlx_image_t	*img;
}				t_mlx;

typedef struct s_fdf
{
	t_point	**points;
	int		x_move;
	int		y_move;
	float	z_move;
	float	zoom;
	int		iso;
	int		win_height;
	int		win_width;
	float	angle;
	char	*file;
	int		color;
	int		width;
	int		height;
	t_mlx	mlx;
	int		dx;
	int		dy;
	int		bonus;
	int		signe;
}			t_fdf;

char			*get_next_line(int fd);
void			draw_map(t_fdf *fdf, t_point **points);
void			free_split(char **strs);
void			free_all(char **strs, char *line);
void			free_points(t_point **points, int height);
void			black_window(t_fdf *fdf);
unsigned int	get_color(t_point p1, t_point p2, float ratio);
int				ft_atoi_base(const char *str, int base);
void			init_map(t_fdf *fdf, char *file_path);
void			intiate_zoom(t_fdf *fdf);
void			initiate_mlx(t_fdf *fdf);
void			redraw_map(t_fdf *fdf, t_point **points);
void			key_hook(mlx_key_data_t keydata, void *param);
void			free_fdf(t_fdf *fdf);
void			mlx_clear(t_fdf *fdf);
t_point			**fill_points(t_fdf *fdf);
void			chech_open_file(t_fdf *fdf, int *fd);
void			scroll_hook(double xdelta, double ydelta, void *param);
void			mouse_hook(mouse_key_t button, action_t action,
					modifier_key_t mods, void *param);
void			loop_hook(void *param);

#endif