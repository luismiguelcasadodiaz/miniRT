/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shadow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:50:27 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/25 19:50:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "eleme.h"
#include "hitrecord.h"
#include "miniRT.h"
#include <math.h>

void    ray_shadow(t_hit_args *data, t_win * w)
{
    t_vec3  offset;
    double distance_to_light;
    double light_intensity;
    double attenuation;
    t_hit_args	*shadow_data;

    shadow_data = (t_hit_args *)malloc(sizeof(t_hit_args));
    shadow_data->rec = hitrecord_new();
	shadow_data->ran = int_new();
	int_init(shadow_data->ran, 0, __DBL_MAX__);
	shadow_data->self = w->eleme;
    vec3_sub(shadow_data->ray->dir, w->light->coor, data->rec->p);
    distance_to_light = vec3_length(shadow_data->ray->dir);
    vec3_unit_vector(shadow_data->ray->dir, shadow_data->ray->dir);
    vec3_scale(&offset, data->rec->normal, 0.01);
    vec3_add(shadow_data->ray->orig, data->rec->p, &offset);
	int_init(shadow_data->ran, 0.001, distance_to_light);
    light_intensity = fmax(0, vec3_dot(data->rec->normal, shadow_data->ray->dir));
    if (eleme_hit(shadow_data)
        hittable_list_hit(world, &shadow_ray, &shadow_ray_t, &shadow_rec)) {
        light_intensity *= 0.1;
    }
    attenuation = w->light->lbrig / (distance_to_light * distance_to_light);
    light_intensity *= attenuation;
    light_intensity = fmax(0, light_intensity);
    data->shadow_col = color_multiply_scalar(w->light->color,light_intensity);
    int_free(shadow_data->ran);
    hitrecord_free(shadow_data->rec);
    free(shadow_data);
}