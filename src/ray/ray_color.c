/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:11:26 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/13 18:09:03 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "eleme.h"
#include "hitrecord.h"
#include "miniRT.h"
#include <math.h>

static	t_vec3	*get_normal(t_ray *self, double t)
{
	t_vec3	*vec3_0_0_minus1;
	t_vec3	*ray_at_t;
	t_vec3	*normal;

	vec3_0_0_minus1 = vec3_new();
	vec3_init_values(vec3_0_0_minus1, 0, 0, -1);
	ray_at_t = ray_at(self, t);
	vec3_sub(ray_at_t, ray_at_t, vec3_0_0_minus1);
	normal = vec3_new();
	vec3_unit_vector(normal, ray_at_t);
	vec3_free(ray_at_t);
	vec3_free(vec3_0_0_minus1);
	return (normal);
}

int	ray_color(t_ray	*self, t_win *w)
{
	int			mlx_color;
	t_vec3		*normal;
	t_color		normalized_color;
	t_hit_args	*data;

	data = (t_hit_args *)malloc(sizeof(t_hit_args));
	data->rec = hitrecord_new();
	data->ran = int_new();
	int_init(data->ran, 0, __DBL_MAX__);
	data->self = w->eleme;
	data->ray = self;
	if (eleme_hit(data))
	{
		normal = get_normal(data->ray, hitrecord_get_t(data->rec));
		//normalized_color = col_new();
		col_init_with_1(&normalized_color, 
			vec3_get_x(&data->self->color->rgb), 
			vec3_get_y(&data->self->color->rgb),
			vec3_get_z(&data->self->color->rgb));
		// col_init_with_1(normalized_color, 0.5 * (1 + vec3_get_x(normal)),
		// 	0.5 * (1 + vec3_get_y(normal)), 0.5 * (1 + vec3_get_z(normal)));
		ray_shadow(data, w);
		col_add(&normalized_color, data->self->color, data->shadow);
		col_add(&normalized_color, &normalized_color, w->ambient->ambient);
		mlx_color = col_get_mlx_color(&normalized_color);
		//mlx_color = col_get_mlx_color(data->rec->hit_obj->color);
		vec3_free(normal);
		//col_free(normalized_color);
		//point_free(rec->p);
	}
	else
		mlx_color = col_lerp(&w->camera->color_start, &w->camera->color_end, self->dir);
	hitrecord_free(data->rec);
	int_free(data->ran);
	free(data);
	return (mlx_color);
}
