/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:32:03 by hipham            #+#    #+#             */
/*   Updated: 2024/05/29 20:10:37 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double r, double i)
{
	int		iter;
	double	pr;
	double	pi;
	double	temp;

	iter = 0;
	pr = 0;
	pi = 0;
	while (pr * pr + pi * pi < 4)
	{
		temp = pr * pr - pi * pi + r;
		pi = 2 * pr * pi + i;
		pr = temp;
		iter++;
		if (iter >= MAX_ITERATIONS)
			break ;
	}
	return (iter);
}

int	julia(t_fractol *ft, double r, double i)
{
	int		iter;
	double	temp_r;

	iter = 0;
	while (r * r + i * i < 4)
	{
		temp_r = r * r - i * i + ft->julia.cr;
		i = 2 * r * i + ft->julia.ci;
		r = temp_r;
		iter++;
		if (iter >= MAX_ITERATIONS)
			break ;
	}
	return (iter);
}

int	burning_ship(double r, double i)
{
	int		iter;
	double	pr;
	double	pi;
	double	temp;

	iter = 0;
	pr = 0;
	pi = 0;
	while (pr * pr + pi * pi < 4)
	{
		temp = pr * pr - pi * pi + r;
		pi = -fabs(2 * pr * pi) + i;
		pr = temp;
		iter++;
		if (iter >= MAX_ITERATIONS)
			break ;
	}
	return (iter);
}

// Julia set for fc, c
// −0.8 + 0.156i
// 0.35 + 0.35i
// −0.4 + 0.6i
// −0.7269 + 0.1889i
// 0.285 + 0.01i
// −0.70176 − 0.3842i
// −0.835 − 0.2321i
