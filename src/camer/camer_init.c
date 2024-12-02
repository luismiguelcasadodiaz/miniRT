/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:00 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/08 17:47:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"
#include "point.h"

/*void	camer_init(t_camer *self)
{
	vec3_init(self->coor);
	vec3_init(self->novec);
	camer_set_fview(self, 0.0);
	//camer_set_vport(self, VIEW_PORT_H);
}
*/

void	camer_set_help(t_camer	*self)
{
	camer_calc_viewport_height(self);
	camer_calc_vierport_width(self);
	camer_calc_w(self);
	camer_calc_u(self);
	camer_calc_v(self);
	camer_calc_viewport_u(self);
	camer_calc_viewport_v(self);
	camer_calc_pixel_delta_u(self);
	camer_calc_pixel_delta_v(self);
	camer_calc_viewport_upper_left(self);
	camer_calc_pixel00_loc(self);
	camer_calc_background_colors(self);
}

t_camer	*camer_set(t_vec3 *coor, t_vec3 *novec, double fview, t_win *w)
{
	t_camer	*self;

	self = camer_new();
	camer_s_coord(self, coor);
	camer_s_novec(self, novec);
	camer_s_hfov(self, fview);
	camer_s_aspect_ratio(self, ASPECT_RATIO_W / ASPECT_RATIO_H);
	camer_s_image_width(self, WINDOW_W);
	camer_calc_image_height(self);
	camer_s_samples_per_pixel(self, 20);
	camer_s_max_depth(self, 10);
	camer_s_vfov(self, self->hfov, w->size);
	camer_calc_pixel_samples_scale(self);
	camer_s_cacen(self);
	camer_s_vup(self, 0, 1, 0);
	camer_s_focal_length(self, 1);
	camer_calc_theta(self);
	camer_calc_h(self);
	camer_set_help(self);
	return (self);
}

	// camer_calc_defocus_radius(self);
	// camer_calc_defocus_disk_u(self);
	// camer_calc_defocus_disk_v(self);
	// camer_s_defocus_angle(self, 0);
	// camer_s_focus_dist(self, 10);
	//camer_s_vport(self, VIEW_PORT_H, w->size);
	//camer_calc_vp_and_pd(self, w->size);
	//camer_calc_vp_ul(self);
	//camer_calc_pix00(self);