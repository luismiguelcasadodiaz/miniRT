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

t_camer	*camer_set(t_vec3 *coor, t_vec3 *novec, double fview, t_win *w)
{
	t_camer	*self;

	self = camer_new();
	camer_s_coord(self, coor);
	camer_s_novec(self, novec);
	camer_s_fview(self, fview);

	// camer_s_aspect_ratio(self, ASPECT_RATIO_H / ASPECT_RATIO_W);
	// camer_s_image_width(self, WINDOW_W);
	// camer_s_samples_per_pixel(self, 10);
	// camer_s_max_depth(self, 10);
	// camer_s_vfov(self, self->hfov, w->size);

	// camer_s_vport(self, VIEW_PORT_H, w->size);
	// camer_s_cacen(self);
	camer_calc_vp_and_pd(self, w->size);
	camer_calc_vp_ul(self);
	camer_calc_pix00(self);
	camer_calc_background_colors(self);
	return (self);
}
