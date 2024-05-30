/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:28:23 by hipham            #+#    #+#             */
/*   Updated: 2024/05/29 20:12:21 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MESSAGE \
	"./fractol mandelbrot\n./fractol julia \
\n./fractol julia <val> <val>\n./fractol burningship"

// define the width and height of the window
# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 56

// define clolors
# define RED 0xFF0000FF
# define GREEN 0x007F7FFF
# define BLUE 0x0000FFFF
# define WHITE 0x0FFFFF0FF
# define LBLUE 0x00F0F0F0
# define BLACK 0x00000000

typedef struct s_color
{
	uint32_t	a;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
}				t_color;

typedef struct s_julia
{
	double		ci;
	double		cr;
}				t_julia;

typedef struct s_fractol
{
	char		*name;
	void		*mlx;
	void		*img;
	int32_t		win;
	int			set;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		i_ptr;
	double		r_ptr;
	int32_t		mx;
	int32_t		my;
	int			signal;
	t_color		palette[255];
	uint32_t	color;
	double		shift_factor;
	t_julia		julia;
	double		zoom;
}				t_fractol;

// Arguments parsing
void			args_handling(t_fractol *ft, int ac, char **av);

// Fractol functions
void			fractol_init(t_fractol *ft);
int				mandelbrot(double r, double i);
int				julia(t_fractol *ft, double r, double i);
int				burning_ship(double r, double i);
int				get_iteration(t_fractol *ft, double r, double i);
void			ft_render(t_fractol *ft);
void			coordinates_setting(t_fractol *fractol);

// Color
uint32_t		get_color(int iter, t_fractol *ft);
uint32_t		convert_to_rgba(t_fractol *ft, uint32_t r, uint32_t g,
					uint32_t b);
void			shift_color(void *param);
// void			fill_color_palette(t_fractol *ft);

// Hook functions
void			my_scrollhook(double xdelta, double ydelta, void *param);
void			ft_keyhook(void *param);
void			switch_fractol(void *param);
void			ft_move(t_fractol *ft, char key);
void			ft_zoom(t_fractol *ft);

// Helper functions in fractol_utils
void			ft_error(t_fractol *f);
void			error_msg(char *s);

#endif