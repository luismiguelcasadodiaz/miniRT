/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_getters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:06 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/14 09:39:42 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "color.h"

int	col_get_t_255(t_color *self)
{
	return (self->t);
}

int	col_get_r_255(t_color *self)
{
	return ((self->mlx_color >> 16) & 0xFF);
}

int	col_get_g_255(t_color *self)
{
	return ((self->mlx_color >> 8) & 0xFF);
}

int	col_get_b_255(t_color *self)
{
	int	mlx_color;

	mlx_color = self->mlx_color;
	return (mlx_color & 0xFF);
}

int	col_get_mlx_color(t_color *self)
{
	return (self->mlx_color);
}
/*
int	col_get_t(int color)
{
	return ((color >> 24) & 0xFF);
}

int	col_get_r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	col_get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	col_get_b(int color)
{
	return (color & 0xFF);
}
*/
