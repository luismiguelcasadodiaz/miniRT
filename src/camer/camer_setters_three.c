/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_setters_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:21:52 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/14 19:37:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "camer.h"

void	camer_s_max_depth(t_camer *self, int dato)
{
	self->max_depth = dato;
}

//self->vfov = hfov; hace una distorsion mayor que la 
//configuracion actual.
//	self->vfov = hfov * (size->e[1] / size->e[0]);
void	camer_s_vfov(t_camer *self)
{
	self->vfov = self->hfov;
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
	// double	aux;

	// aux = vec3_length(&self->coor);
	// if (aux != 0)
	// 	self->focal_lenght = dist * aux;
	// else
		self->focal_lenght = dist;
}

void	camer_s_focal_length_ave(t_win *w)
{
	t_vec3		d;
	t_vec3		average;
	double	aux;
	

	average = eleme_average_coor(w->eleme);
	vec3_sub(&d, &average, &w->camera->coor);
	aux = vec3_length(&d);
	if (aux != 0)
		camer_u_focal_lenght(w->camera, aux);
	else
		camer_u_focal_lenght(w->camera, 1);
}
