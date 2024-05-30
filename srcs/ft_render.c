/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:28:51 by hipham            #+#    #+#             */
/*   Updated: 2024/05/23 21:26:51 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
oldtop											newtop
	|												|
oldleft	______________________oldright		newleft	________________________newright
		|					|						|						|
		|					|						|	.(newX, newY)		|
		|					|						|						|
		|					|						|						|
		|.(oldX, oldY)		|						|						|
		|					|						|						|
		|					|						|						|
oldbot	______________________					newbot	_________________________
*/

/*
newX = newLeft + ((oldX - oldLeft)/(oldRight - oldLeft)) * (newRight - newLeft))
newY = newTop + ((oldY - oldTop)/(oldBottom - oldTop)) * (newBottom - newTop)

MAPPING COORDINATES FORMULAR PIXEL -> MANDEL COMPLEX PLANE
---------------------------------------------
real = min_r + (x / WIDTH) * (max_r - min_r)
i = max_i + (y / HEIGHT) * (min_i - max_i)
---------------------------------------------
*/

#include "fractol.h"

// static void	ft_zoom(t_fractol *ft, double *r, double *i)
// {
// 	*r = *r * ft->zoom;
// 	*i = *i * ft->zoom;
// }

void	ft_zoom(t_fractol *ft)
{
	double	mouse_r;
	double	mouse_i;

	mouse_r = ft->min_r + (((double)ft->mx / WIDTH) * (ft->max_r - ft->min_r));
	mouse_i = ft->max_i + (((double)ft->my / HEIGHT) * (ft->min_i - ft->max_i));
	ft->min_r = mouse_r + (ft->min_r - mouse_r) * ft->zoom;
	ft->max_r = mouse_r + (ft->max_r - mouse_r) * ft->zoom;
	ft->min_i = mouse_i + (ft->min_i - mouse_i) * ft->zoom;
	ft->max_i = mouse_i + (ft->max_i - mouse_i) * ft->zoom;
}

int	get_iteration(t_fractol *ft, double r, double i)
{
	int	iter;

	iter = 0;
	if (ft->set == 1)
		iter = mandelbrot(r, i);
	if (ft->set == 2 || ft->set == 3)
		iter = julia(ft, r, i);
	if (ft->set == 4)
		iter = burning_ship(r, i);
	return (iter);
}

void	ft_render(t_fractol *ft)
{
	int			iter;
	uint32_t	x;
	uint32_t	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			ft->r_ptr = ft->min_r + ((double)x / WIDTH) * (ft->max_r
					- ft->min_r);
			ft->i_ptr = ft->max_i + ((double)y / HEIGHT) * (ft->min_i
					- ft->max_i);
			iter = get_iteration(ft, ft->r_ptr, ft->i_ptr);
			if (iter == MAX_ITERATIONS)
				ft->color = WHITE;
			else
				ft->color = get_color(iter, ft);
			mlx_put_pixel(ft->img, x, y, ft->color);
		}
	}
}
