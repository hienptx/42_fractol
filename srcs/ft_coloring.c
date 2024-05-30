/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coloring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:54:34 by hipham            #+#    #+#             */
/*   Updated: 2024/05/29 20:10:45 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shift_color(void *param)
{
	t_fractol	*ft;

	ft = param;
	if (mlx_is_key_down(ft->mlx, MLX_KEY_A))
		ft->shift_factor += 0.1;
	if (mlx_is_key_down(ft->mlx, MLX_KEY_D))
		ft->shift_factor -= 0.1;
}

uint32_t	convert_to_rgba(t_fractol *ft, uint32_t r, uint32_t g, uint32_t b)
{
	uint32_t	shifted_r;
	uint32_t	shifted_g;
	uint32_t	shifted_b;

	shifted_r = (uint32_t)(r * ft->shift_factor);
	shifted_g = (uint32_t)(g * ft->shift_factor);
	shifted_b = (uint32_t)(b * ft->shift_factor);
	return (shifted_r << 16 | shifted_g << 8 | shifted_b);
}

uint32_t	get_color(int iter, t_fractol *ft)
{
	uint32_t	c;

	if (iter > 255)
		return (LBLUE);
	else
		c = convert_to_rgba(ft, ft->palette[iter].r, ft->palette[iter].g,
				ft->palette[iter].b);
	return (c);
}
