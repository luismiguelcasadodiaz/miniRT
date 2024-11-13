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

/* ************************************************************************** */
/* vp_x kcamera center - (0, 0, focal_lenge) - vp_y/2 -vp_y/	              */
/* ************************************************************************** */
void	camer_calculate_vp_and_pd(t_camer *self, t_point *size)
{
	self->vp_x = vec3_new();
	vec3_init_values(self->vp_x, self->vport->e[0], 0, 0);
	self->vp_y = vec3_new();
	vec3_init_values(self->vp_y, 0, -self->vport->e[1], 0);
	self->pd_x = vec3_new();
	vec3_div(self->pd_x, self->vp_x, size->e[0]);
	self->pd_y = vec3_new();
	vec3_div(self->pd_y, self->vp_y, size->e[1]);
}

/* ************************************************************************** */
/* vp_ul = camera center - (0, 0, focal_lenge) - vp_y/2 -vp_y/	              */
/* ************************************************************************** */
void	camer_calculate_vp_ul(t_camer *w)
{
	t_vec3	*aux;

	aux = vec3_new();
	vec3_init_values(aux, 0, 0, FOCAL_LENGTH);
	w->vp_ul = vec3_new();
	vec3_init_values(w->vp_ul, w->cacen->e[0], w->cacen->e[1], w->cacen->e[2]);
	vec3_sub(w->vp_ul, w->vp_ul, aux);
	vec3_div(aux, w->vp_x, 2);
	vec3_sub(w->vp_ul, w->vp_ul, aux);
	vec3_div(aux, w->vp_y, 2);
	vec3_sub(w->vp_ul, w->vp_ul, aux);
	vec3_free(aux);
}

/* ************************************************************************** */
/* pixel00  = view port Upper lef + 0.5 *(pixel delta x + pixel delta y)      */
/* ************************************************************************** */
void	camer_calculate_pix00(t_camer *w)
{
	w->pixel00 = vec3_new();
	vec3_add(w->pixel00, w->pd_x, w->pd_y);
	vec3_div(w->pixel00, w->pixel00, 2);
	vec3_add(w->pixel00, w->pixel00, w->vp_ul);
}

void	camer_calculate_background_colors(t_camer *w)
{
	w->color_start = col_new();
	w->color_end = col_new();
	col_init_with_1(w->color_start, 1.0, 1.0, 1.0);
	col_init_with_1(w->color_end, 0.5, 0.7, 1.0);
}

void	camer_calc_image_height(t_camer *self)
{
	int	aux;

	aux = (int)(self->image_width / self->aspect_ratio);
	if (aux < 1)
		self->image_height = 1;
	else
		self->image_height = aux;
}

void	camer_calc_pixel_samples_scale(t_camer *self)
{
	self->pixel_samples_scale = 1.0 / self->samples_per_pixel;
}

void	camer_calc_theta(t_camer *self)
{
	self->theta = (self->vfov * M_PI) / 180.0;
}

void	camer_calc_h(t_camer *self)
{
	self->h = tan(self->theta / 2);
}

void	camer_calc_viewport_height(t_camer *self)
{
	self->viewport_height = 2 * self->h * self->focus_dist;
}

void	camer_calc_vierport_width(t_camer *self)
{
	self->viewport_width = self->viewport_height
		* (double)(self->image_width / self->image_height);
}

void	camer_calc_w(t_camer *self)
{
	t_vec3	aux;

	vec3_sub(&aux, self->lookfrom, self->lookat);
	vec3_unit_vector(self->w, &aux);
}

void	camer_calc_u(t_camer *self)
{
	t_vec3	aux;

	vec3_cross(&aux, self->vup, self->w);
	vec3_unit_vector(self->u, &aux);
}

void	camer_calc_v(t_camer *self)
{
	vec3_cross(self->v, self->w, self->u);
}

void	camer_calc_viewport_u(t_camer *self)
{
	vec3_mul(self->vp_u, self->u, self->viewport_width);
}

void	camer_calc_viewport_v(t_camer *self)
{
	t_vec3	aux;

	vec3_negate(&aux, self->v);
	vec3_mul(self->vp_v, &aux, self->viewport_height);
}

void	camer_calc_pixel_delta_u(t_camer *self)
{
	vec3_div(self->pd_u, self->vp_u, self->image_width);
}

void	camer_calc_pixel_delta_v(t_camer *self)
{
	vec3_div(self->pd_v, self->vp_v, self->image_height);
}

//viewport_upper_left = center - (focus_dist * w) - viewport_u/2 - viewport_v/2;
void	camer_calc_viewport_upper_left(t_camer *self)
{
	t_vec3	aux_u;
	t_vec3	aux_v;
	t_vec3	aux_w;
	t_vec3	suma;

	vec3_div(&aux_u, self->vp_u, 2);
	vec3_div(&aux_v, self->vp_v, 2);
	vec3_mul(&aux_w, self->w, self->focus_dist);
	vec3_add(&suma, &aux_u, &aux_v);
	vec3_add(&suma, &suma, &aux_w);
	vec3_sub(self->vp_ul, self->center, &suma);
}

void	camer_calc_pixel00_loc(t_camer *self)
{
}

void	camer_calc_defocus_radius(t_camer *self)
{
}

void	camer_calc_defocus_disk_u(t_camer *self)
{
}

void	camer_calv_defocus_disk_v(t_camer *self)
{
}
