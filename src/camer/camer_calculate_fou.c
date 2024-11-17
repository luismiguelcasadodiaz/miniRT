/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_calculate_vp_ul.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:09:47 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/13 20:43:17 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"
#include <math.h>

void	camer_calc_pixel_delta_u(t_camer *self)
{
	vec3_div(&self->pd_u, &self->vp_u, self->image_width);
}

void	camer_calc_pixel_delta_v(t_camer *self)
{
	vec3_div(&self->pd_v, &self->vp_v, self->image_height);
}

//viewport_upper_left = center - (focus_dist * w) - viewport_u/2 - viewport_v/2;
void	camer_calc_viewport_upper_left(t_camer *self)
{
	t_vec3	aux_u;
	t_vec3	aux_v;
	t_vec3	aux_w;
	t_vec3	suma;

	vec3_div(&aux_u, &self->vp_u, 2);
	vec3_div(&aux_v, &self->vp_v, 2);
	vec3_mul(&aux_w, &self->w, self->focus_dist);
	vec3_add(&suma, &aux_u, &aux_v);
	vec3_add(&suma, &suma, &aux_w);
	vec3_sub(&self->vp_ul, &self->center, &suma);
}

void	camer_calc_pixel00_loc(t_camer *self)
{
	t_vec3	aux;

	vec3_add(&aux, &self->pd_u, &self->pd_v);
	vec3_mul(&aux, &aux, 0.5);
	vec3_add(&self->pixel00_loc, &self->vp_ul, &aux);
}

void	camer_calc_defocus_radius(t_camer *self)
{
	self->defocus_radius = self->focus_dist
		* tan(((self->defocus_angle / 2) * M_PI) / 180);
}
