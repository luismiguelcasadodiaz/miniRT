/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_calculate_fou.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:09:47 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/14 19:38:15 by luicasad         ###   ########.fr       */
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

//viewport_upper_left = 
//                 center - (focal_lenght * w) - viewport_u/2 - viewport_v/2;
void	camer_calc_viewport_upper_left(t_camer *self)
{
	t_vec3	aux_u;
	t_vec3	aux_v;
	t_vec3	aux_w;
	t_vec3	suma;

	vec3_div(&aux_u, &self->vp_u, 2);
	vec3_div(&aux_v, &self->vp_v, 2);
	vec3_mul(&aux_w, &self->w, self->focal_lenght);
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
/*
void	camer_calc_defocus_radius(t_camer *self)
{
	self->defocus_radius = self->focus_dist
		* tan(((self->defocus_angle / 2) * M_PI) / 180);
}
*/

void	camer_calc_background_colors_ambil(t_camer *self, t_color *ambil)
{
	col_init_with_1(&self->color_start,
		ambil->rgb.e[0],
		ambil->rgb.e[1],
		ambil->rgb.e[2]);
	col_init_with_1(&self->color_end,
		ambil->rgb.e[0],
		ambil->rgb.e[1],
		ambil->rgb.e[2]);
}
