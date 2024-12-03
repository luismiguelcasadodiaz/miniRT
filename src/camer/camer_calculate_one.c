/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_calculate_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:09:47 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/14 20:39:15 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"
#include <math.h>

/* ************************************************************************** */
/* vp_x kcamera center - (0, 0, focal_lenge) - vp_y/2 -vp_y/	              */
/* ************************************************************************** */
void	camer_calc_vp_and_pd(t_camer *self, t_point *size)
{
	vec3_init_values(&self->vp_u, self->vport.e[0], 0, 0);
	vec3_init_values(&self->vp_v, 0, -self->vport.e[1], 0);
	vec3_div(&self->pd_u, &self->vp_u, size->e[0]);
	vec3_div(&self->pd_v, &self->vp_v, size->e[1]);
}

/* ************************************************************************** */
/* vp_ul = camera center - (0, 0, focal_lenge) - vp_y/2 -vp_y/	              */
/* ************************************************************************** */
void	camer_calc_vp_ul(t_camer *w)
{
	t_vec3	aux;

	vec3_init_values(&aux, 0, 0, FOCAL_LENGTH);
	vec3_init_values(&w->vp_ul, w->lookfrom.e[0], w->lookfrom.e[1],
		w->lookfrom.e[2]);
	vec3_sub(&w->vp_ul, &w->vp_ul, &aux);
	vec3_div(&aux, &w->vp_u, 2);
	vec3_sub(&w->vp_ul, &w->vp_ul, &aux);
	vec3_div(&aux, &w->vp_v, 2);
	vec3_sub(&w->vp_ul, &w->vp_ul, &aux);
}

/* ************************************************************************** */
/* pixel00  = view port Upper lef + 0.5 *(pixel delta x + pixel delta y)      */
/* ************************************************************************** */
void	camer_calc_pix00(t_camer *w)
{
	vec3_add(&w->pixel00_loc, &w->pd_u, &w->pd_v);
	vec3_div(&w->pixel00_loc, &w->pixel00_loc, 2);
	vec3_add(&w->pixel00_loc, &w->pixel00_loc, &w->vp_ul);
}

void	camer_calc_background_colors(t_camer *self)
{
	col_init_with_1(&self->color_start, 0.0, 0.0, 0.0);
	col_init_with_1(&self->color_end, 0.011764, 0.956863, 0.988235);
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
