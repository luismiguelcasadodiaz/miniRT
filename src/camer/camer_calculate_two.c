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
