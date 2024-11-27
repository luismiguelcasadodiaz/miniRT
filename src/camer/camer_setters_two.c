/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_setters_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:21:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/27 20:21:40 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "camer.h"

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
