/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shadow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:50:27 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/27 20:37:27 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "eleme.h"
#include "hitrecord.h"
#include "miniRT.h"
#include <math.h>

void	ray_shadow(t_hit_args *data, t_win *w)
{
	t_vec3		offset;
	double		distance_to_light;
	double		light_inte;
	double		attenuation;
	t_hit_args	*shadow_data;

	shadow_data = (t_hit_args *)malloc(sizeof(t_hit_args));
	shadow_data->rec = hitrecord_new();
	shadow_data->ran = int_new();
	shadow_data->ray = ray_new();
	int_init(shadow_data->ran, 0, __DBL_MAX__);
	shadow_data->self = w->eleme;
	vec3_sub(shadow_data->ray->dir, w->light->coor, data->rec->p);
	distance_to_light = vec3_length(shadow_data->ray->dir);
	vec3_unit_vector(shadow_data->ray->dir, shadow_data->ray->dir);
	vec3_scale(&offset, data->rec->normal, 0.01);
	vec3_add(shadow_data->ray->orig, data->rec->p, &offset);
	int_init(shadow_data->ran, 0.001, distance_to_light);
	light_inte = fmax(0, vec3_dot(data->rec->normal, shadow_data->ray->dir));
	if (eleme_hit(shadow_data))
		light_inte *= 0.1;
	attenuation = w->light->lbrig / (distance_to_light * distance_to_light);
	light_inte *= attenuation;
	light_inte = fmax(0, light_inte);
	col_scale(data->shadow_col, w->light->color, light_inte);
	int_free(shadow_data->ran);
	hitrecord_free(shadow_data->rec);
	ray_free(shadow_data->ray);
	free(shadow_data);
}
