/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_setters1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:06 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/14 10:31:23 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "color.h"

void	col_set_r_1(t_color *self, double value)
{
	vec3_set_x(self->rgb, value);
	col_create_mlx_color(self);
}

void	col_set_g_1(t_color *self, double value)
{
	vec3_set_y(self->rgb, value);
	col_create_mlx_color(self);
}

void	col_set_b_1(t_color *self, double value)
{
	vec3_set_z(self->rgb, value);
	col_create_mlx_color(self);
}

void	col_set_t_1(t_color *self, double value)
{
	self->t = (int)(255.999 * value);
	col_create_mlx_color(self);
}
/*
double	col_set_t(int c, int t)
{
	return (c | (t << 24));
}

double	col_set_r(int c, int r)
{
	return (c | (r << 16));
}

double	col_set_g(int c, int g)
{
	return (c | (g << 8));
}

double	col_set_b(int c, int b)
{
	return (c | b);
}
*/
