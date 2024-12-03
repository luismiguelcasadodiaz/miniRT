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

/*
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
*/

t_color	ray_color(t_ray	*self, int depth, t_win *w)
{
	//t_vec3		*normal;
	t_vec3		direction;
	t_color		normalized_color;
	t_hit_args	*data;
	t_ray		*ray_diffuse;

	if (depth <= 0)
	{
		col_init_with_1(&normalized_color, 0, 0, 0);
		return (normalized_color);
	}

	data = hit_args_new_l();
	int_init(data->ran, 0, __DBL_MAX__);
	data->self = w->eleme;
	data->ray = self;
	if (eleme_hit(data))
	{
		//difuse version
		vec3_random_on_hemisphere(data->rec->normal, &direction);
		ray_diffuse = ray_new();
		ray_init(ray_diffuse, data->rec->p, &direction);
		normalized_color = ray_color(ray_diffuse, depth - 1, w);
		col_scale(&normalized_color, &normalized_color, 0.9);
		ray_free(ray_diffuse);
		return (normalized_color);
		//Antialiasing version
		// normal = get_normal(data->ray, hitrecord_get_t(data->rec));
		// col_init_with_1(&normalized_color,
		// 	vec3_get_x(&data->rec->hit_obj->color->rgb),
		// 	vec3_get_y(&data->rec->hit_obj->color->rgb),
		// 	vec3_get_z(&data->rec->hit_obj->color->rgb));
		// ray_shadow(data, w);
		// col_add(&normalized_color, &normalized_color, data->shadow_col);
		// col_add(&normalized_color, &normalized_color, w->ambient->ambient);
		// vec3_free(normal);
	}
	else
		normalized_color = col_lerp(w, self->dir);
	hit_args_free_l(data);
	return (normalized_color);
}

		// col_init_with_1(&normalized_color, 0.5 * (1 + vec3_get_x(normal)),
		// 	0.5 * (1 + vec3_get_y(normal)), 0.5 * (1 + vec3_get_z(normal)));

		//mlx_color = col_get_mlx_color(&normalized_color);
		//mlx_color = col_get_mlx_color(data->rec->hit_obj->color);
