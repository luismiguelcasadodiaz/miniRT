/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:11:26 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 12:42:25 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "eleme.h"
#include "hitrecord.h"
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

int	ray_color(t_ray	*self, t_color color_start, t_color color_end, t_eleme *o)
{
	int			mlx_color;
	t_vec3		*normal;
	t_color		*normalized_color;
	t_hitrecord	*rec;
	t_interval	*range;

	rec = hitrecord_new();
	range = interval_new();
	interval_init(range, 0, __DBL_MAX__);
	if (eleme_hit(o, self, range, rec))
	{
		normal = get_normal(self, hitrecord_get_t(rec));
		normalized_color = col_new();
		col_init_with_1(normalized_color, 0.5 * (1 + vec3_get_x(normal)),
			0.5 * (1 + vec3_get_y(normal)), 0.5 * (1 + vec3_get_z(normal)));
		mlx_color = col_get_mlx_color(normalized_color);
		mlx_color = col_get_mlx_color(rec->hit_obj->color);
		vec3_free(normal);
		col_free(normalized_color);
		//point_free(rec->p);
	}
	else
		mlx_color = col_lerp(&color_start, &color_end, self->dir);
	hitrecord_free(rec);
	interval_free(range);
	return (mlx_color);
}
