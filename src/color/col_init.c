/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:06 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/14 10:32:00 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "color.h"

static int	col_create_mlx_color_with_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	col_create_mlx_color_with_double(t_vec3 *the_rgb, double the_t)
{
	int	r_int;
	int	g_int;
	int	b_int;
	int	t_int;

	r_int = (int)(255.999 * vec3_get_x(the_rgb));
	g_int = (int)(255.999 * vec3_get_y(the_rgb));
	b_int = (int)(255.999 * vec3_get_z(the_rgb));
	t_int = (int)(255.999 * the_t);
	return (col_create_mlx_color_with_int(t_int, r_int, g_int, b_int));
}

void	col_create_mlx_color(t_color *self)
{
	self->mlx_color = col_create_mlx_color_with_double(self->rgb, self->t);
}

// to use when color are in range 0 .. 255
void	col_init_with_255(t_color *self, int r, int g, int b)
{
	col_init_with_1(self,
		(double)(r / 255),
		(double)(g / 255),
		(double)(b / 255));
}

// to use when colors are in range 0.0 .. 1.0
void	col_init_with_1(t_color *self, double r, double g, double b)
{
	vec3_init_values(self->rgb, r, g, b);
	self->t = 0;
	col_create_mlx_color(self);
}
