/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_setters_four.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:04 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/16 08:50:55 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "camer.h"

void	camer_u_hfov(t_camer *self, double change)
{
	double	aux;

	aux = self->hfov + change;
	if (HFOV_MIN <= aux && aux <= HFOV_MAX)
	{
		camer_s_hfov(self, aux);
		camer_s_vfov(self);
		camer_calc_theta(self);
		camer_calc_h(self);
		camer_calc_viewport_height(self);
		camer_calc_vierport_width(self);
		camer_calc_viewport_u(self);
		camer_calc_viewport_v(self);
		camer_calc_pixel_delta_u(self);
		camer_calc_pixel_delta_v(self);
		camer_calc_viewport_upper_left(self);
		camer_calc_pixel00_loc(self);
	}
}

void	camer_u_focal_lenght(t_camer *self, double new_value)
{
	self->focal_lenght = new_value;
	camer_calc_viewport_height(self);
	camer_calc_vierport_width(self);
	camer_calc_viewport_u(self);
	camer_calc_viewport_v(self);
	camer_calc_pixel_delta_u(self);
	camer_calc_pixel_delta_v(self);
	camer_calc_viewport_upper_left(self);
	camer_calc_pixel00_loc(self);
}
