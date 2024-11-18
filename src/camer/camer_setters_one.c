/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_setters_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:04 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/03 20:27:31 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"

void	camer_s_coord(t_camer *self, t_vec3 *coor)
{
	vec3_copy_values(&self->coor, coor);
}

void	camer_s_novec(t_camer *self, t_vec3 *novec)
{
	vec3_copy_values(&self->novec, novec);
}

void	camer_s_hfov(t_camer *self, double hfov)
{
	self->hfov = hfov;
}

void	camer_s_vport(t_camer *self, double the_vp_h, t_point *size)
{
	point_init(&self->vport,
		the_vp_h * (size->e[0] / size->e[1]),
		the_vp_h, 0);
}

void	camer_s_cacen(t_camer *self)
{
	point_init(&self->lookfrom, self->coor.e[0],
		self->coor.e[1], self->coor.e[2]);
	vec3_add(&self->lookat, &self->lookfrom, &self->novec);
}

void	camer_s_vup(t_camer *self, double x, double y, double z)
{
	vec3_init_values(&self->vup, x, y, z);
}

void	camer_s_aspect_ratio(t_camer *self, double dato)
{
	self->aspect_ratio = dato;
}

void	camer_s_image_width(t_camer *self, int dato)
{
	self->image_width = dato;
}

void	camer_s_samples_per_pixel(t_camer *self, int dato)
{
	self->samples_per_pixel = dato;
}

void	camer_s_max_depth(t_camer *self, int dato)
{
	self->max_depth = dato;
}

void	 camer_s_vfov(t_camer *self, float hfov, t_point *size)
{
	self->vfov = hfov * (size->e[1] / size->e[0]);
	self->vfov = hfov;
}

void			camer_s_defocus_angle(t_camer *self, double angle)
{
	self->defocus_angle = angle;
}


void			camer_s_focus_dist(t_camer *self, double dist)
{
	self->focus_dist = dist;
}
/*
void	camer_set_isize(t_camer *self, double win_w, double aspect_ratio)
{
	int	height;

	height = (int)(win_w * aspect_ratio);
	if (height < 1.0)
		height = 1;
	self->size = point_new();
	if (self->size)
		point_init(self->size, win_w, height, 0);
}
*/
