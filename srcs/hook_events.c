/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:22:36 by hipham            #+#    #+#             */
/*   Updated: 2024/05/22 16:02:42 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(t_fractol *ft, char key)
{
	if (key == 'U')
	{
		ft->max_i -= 0.1;
		ft->min_i -= 0.1;
	}
	if (key == 'D')
	{
		ft->max_i += 0.1;
		ft->min_i += 0.1;
	}
	if (key == 'R')
	{
		ft->max_r -= 0.1;
		ft->min_r -= 0.1;
	}
	if (key == 'L')
	{
		ft->max_r += 0.1;
		ft->min_r += 0.1;
	}
}

void	switch_fractol(void *param)
{
	t_fractol	*ft;

	ft = param;
	if (mlx_is_key_down(ft->mlx, MLX_KEY_M))
	{
		ft->set = 1;
		coordinates_setting(ft);
	}
	if (mlx_is_key_down(ft->mlx, MLX_KEY_J))
	{
		ft->set = 2;
		coordinates_setting(ft);
	}
	if (mlx_is_key_down(ft->mlx, MLX_KEY_B))
	{
		ft->set = 4;
		coordinates_setting(ft);
	}
}

void	ft_keyhook(void *param)
{
	t_fractol	*ft;

	ft = param;
	if (!ft || !ft->mlx || !ft->img)
		return ;
	if (mlx_is_key_down(ft->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(ft->mlx);
	if (mlx_is_key_down(ft->mlx, MLX_KEY_UP))
		ft_move(ft, 'U');
	if (mlx_is_key_down(ft->mlx, MLX_KEY_DOWN))
		ft_move(ft, 'D');
	if (mlx_is_key_down(ft->mlx, MLX_KEY_LEFT))
		ft_move(ft, 'L');
	if (mlx_is_key_down(ft->mlx, MLX_KEY_RIGHT))
		ft_move(ft, 'R');
	switch_fractol(ft);
	shift_color(ft);
	ft_render(ft);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*ft;

	ft = param;
	mlx_get_mouse_pos(ft->mlx, &ft->mx, &ft->my);
	if (ydelta > 0)
		ft->zoom = 1.05;
	else if (ydelta < 0)
		ft->zoom = 0.95;
	else
		return ;
	xdelta = 0;
	ft_zoom(ft);
	ft_render(ft);
}
