/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:56:10 by hipham            #+#    #+#             */
/*   Updated: 2024/05/29 20:09:15 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * PROJECT

Julia & Mandelbrotset
Infinite Zoom
Able to take command line args to disipline which fractal render
ESC closes the process with no leaks
Click on the X window, closes the process leaks __has_feature

*ft = (t_fractol) {
		.name = NULL,
		.mlx =
	};
**/

#include "fractol.h"

void	struct_init(t_fractol *ft)
{
	ft->name = NULL;
	ft->mlx = NULL;
	ft->img = NULL;
	ft->win = -1;
	ft->set = -1;
	ft->min_r = 0;
	ft->max_r = 0;
	ft->min_i = 0;
	ft->max_i = 0;
	ft->color = 0;
	ft->shift_factor = 1;
	ft->julia.cr = -0.8;
	ft->julia.ci = 0.156;
	ft->mx = 0;
	ft->my = 0;
	ft->i_ptr = 0;
	ft->r_ptr = 0;
	ft->zoom = 1;
}

void	coordinates_setting(t_fractol *fractol)
{
	if (fractol->set == 1)
	{
		fractol->max_r = 1;
		fractol->min_r = -2;
		fractol->max_i = 1.5;
		fractol->min_i = -1.5;
	}
	else if (fractol->set == 2 || fractol->set == 3 || fractol->set == 4)
	{
		fractol->max_r = 2;
		fractol->min_r = -2;
		fractol->max_i = 2;
		fractol->min_i = -2;
	}
}

void	fractol_init(t_fractol *ft)
{
	ft->mlx = mlx_init(WIDTH, HEIGHT, ft->name, false);
	if (!ft->mlx)
		ft_error(ft);
	ft->img = mlx_new_image(ft->mlx, WIDTH, HEIGHT);
	if (!ft->img)
		ft_error(ft);
	coordinates_setting(ft);
}

int	main(int ac, char **av)
{
	t_fractol	ft;

	if (ac < 2)
		error_msg(MESSAGE);
	struct_init(&ft);
	args_handling(&ft, ac, av);
	if (ft.set == -1)
		error_msg(MESSAGE);
	fractol_init(&ft);
	ft_render(&ft);
	ft.win = mlx_image_to_window(ft.mlx, ft.img, 0, 0);
	if (ft.win == -1)
		ft_error(&ft);
	mlx_scroll_hook(ft.mlx, &my_scrollhook, &ft);
	mlx_loop_hook(ft.mlx, ft_keyhook, &ft);
	mlx_loop(ft.mlx);
	mlx_terminate(ft.mlx);
	return (0);
}

// void leaks(void)
// {
// 	system("leaks fractol");
// }
// atexit(leaks);
