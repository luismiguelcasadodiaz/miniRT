/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_calculate_vp_ul.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:09:47 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/02 20:35:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"

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
