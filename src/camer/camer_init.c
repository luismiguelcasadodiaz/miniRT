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

t_camer	*camer_set(t_vec3 *coor, t_vec3 *novec, double fview, t_point *size)
{
	t_camer	*self;

	self = camer_new();
	camer_set_coord(self, coor);
	camer_set_novec(self, novec);
	camer_set_fview(self, fview);
	camer_set_vport(self, VIEW_PORT_H, size);
	camer_set_cacen(self);
	camer_calculate_vp_and_pd(self, size);
	camer_calculate_vp_ul(self);
	camer_calculate_pix00(self);
	camer_calculate_background_colors(self);
	return (self);
}
