/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:56:59 by hipham            #+#    #+#             */
/*   Updated: 2024/05/29 20:09:31 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(t_fractol *f)
{
	mlx_terminate(f->mlx);
	ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}

void	error_msg(char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_SUCCESS);
}
