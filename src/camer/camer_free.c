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
	/*
	if (self->coor)
		vec3_free(self->coor);
	if (self->novec)
		vec3_free(self->novec);
	if (self->lookfrom)
		point_free(self->lookfrom);
	if (self->lookat)
		point_free(self->lookat);
	if (self->vup)
		point_free(self->lookat);
	if (self->vport)
		point_free(self->vport);

	if (self->vp_u)
		vec3_free(self->vp_u);
	if (self->vp_v)
		vec3_free(self->vp_v);
	if (self->pd_u)
		vec3_free(self->pd_u);
	if (self->pd_v)
		vec3_free(self->pd_v);
	if (self->vp_ul)
		vec3_free(self->vp_ul);
	if (self->pixel00)
		vec3_free(self->pixel00);
	
	if (self->color_start)
		col_free(self->color_start);
	if (self->color_end)
		col_free(self->color_end);
		*/
	free(self);
}
