/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:31:04 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/03 20:31:48 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"

void	camer_free(t_camer *self)
{
	if (self->coor)
		vec3_free(self->coor);
	if (self->novec)
		vec3_free(self->novec);
	if (self->vport)
		point_free(self->vport);
	if (self->cacen)
		point_free(self->cacen);
	if (self->vp_x)
		vec3_free(self->vp_x);
	if (self->vp_y)
		vec3_free(self->vp_y);
	if (self->pd_x)
		vec3_free(self->pd_x);
	if (self->pd_y)
		vec3_free(self->pd_y);
	if (self->vp_ul)
		vec3_free(self->vp_ul);
	if (self->pixel00)
		vec3_free(self->pixel00);
	if (self->color_start)
		col_free(self->color_start);
	if (self->color_end)
		col_free(self->color_end);
	free(self);
}
