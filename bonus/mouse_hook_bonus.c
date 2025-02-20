/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:41:17 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/20 01:19:22 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	mouse_hook(mouse_key_t button, action_t action,
			modifier_key_t mods, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (!fdf || !fdf->bonus)
		return ;
	(void)mods;
	if (button == 0 && action == 1)
		fdf->x_move -= 20;
	else if (button == 1 && action == 1)
		fdf->x_move += 20;
	else if (button == 2 && action == 1)
	{
		fdf->signe = !fdf->signe;
		return ;
	}
	redraw_map(fdf, fdf->points);
}

void	loop_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->signe)
	{
		fdf->angle += 1;
		redraw_map(fdf, fdf->points);
	}
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (!fdf->bonus)
		return ;
	xdelta = 0;
	if (ydelta > 0)
		fdf->zoom += 1;
	else
		fdf->zoom -= 1;
	redraw_map(fdf, fdf->points);
}
