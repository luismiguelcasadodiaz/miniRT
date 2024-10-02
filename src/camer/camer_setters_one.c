/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_setters_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:04 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/02 20:18:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"

void	camer_set_coord(t_camer *self, t_vec3 *coor)
{
	vec3_copy_values(self->coor, coor);
}

void	camer_set_novec(t_camer *self, t_vec3 *novec)
{
	vec3_copy_values(self->novec, novec);
}

void	camer_set_fview(t_camer *self, double fview)
{
	self->fview = fview;

}

void	camer_set_vport(t_camer *self, double the_vp_h)
{
	point_init(self->vport,
	the_vp_h * ((double)self->vport->e[0] / (double)self->vport->e[1]),
	the_vp_h, 0);
}

void	camer_set_cacen(t_camer *self)
{
	self->cacen = point_new();
	point_init(self->cacen, 0, 0, 0);
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
