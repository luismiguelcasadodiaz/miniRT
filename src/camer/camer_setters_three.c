/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_setters_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:21:52 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/27 20:27:43 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "camer.h"

void	camer_s_max_depth(t_camer *self, int dato)
{
	self->max_depth = dato;
}

//self->vfov = hfov; hace una distorsion mayor que la 
//configuracion actual.
void	camer_s_vfov(t_camer *self, float hfov, t_point *size)
{
	self->vfov = hfov * (size->e[1] / size->e[0]);
	self->vfov = hfov;
}

/*
void	camer_s_defocus_angle(t_camer *self, double angle)
{
	self->defocus_angle = angle;
}


void			camer_s_focus_dist(t_camer *self, double dist)
{
	self->focus_dist = dist;
}
*/

void	camer_s_focal_length(t_camer *self, double dist)
{
	self->focal_lenght = dist * vec3_length(&self->coor);
}

void	camer_s_focal_length_ave(t_win *w)
{
	t_vec3		d;
	t_vec3		average;

	average = eleme_average_coor(w->eleme);
	vec3_sub(&d, &w->camera->coor, &average);
	w->camera->focal_lenght = vec3_length(&d);
}
