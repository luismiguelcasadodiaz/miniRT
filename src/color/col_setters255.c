/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_setters_255.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:06 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/14 10:25:07 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "color.h"

void	col_set_r_255(t_color *self, int value)
{
	vec3_set_x(self->rgb, (double)(value / 255.0));
	col_create_mlx_color(self);
}

void	col_set_g_255(t_color *self, int value)
{
	vec3_set_y(self->rgb, (double)(value / 255.0));
	col_create_mlx_color(self);
}

void	col_set_b_255(t_color *self, int value)
{
	vec3_set_z(self->rgb, (double)(value / 255.0));
	col_create_mlx_color(self);
}

void	col_set_t_255(t_color *self, int value)
{
	self->t = value;
	col_create_mlx_color(self);
}
/*
int	col_set_t(int c, int t)
{
	return (c | (t << 24));
}

int	col_set_r(int c, int r)
{
	return (c | (r << 16));
}

int	col_set_g(int c, int g)
{
	return (c | (g << 8));
}

int	col_set_b(int c, int b)
{
	return (c | b);
}
*/
