/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:00 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/02 20:22:02 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"
static void try_alloc_cacen(t_camer *self)
{
	self->cacen = point_new();
	if (!self->cacen)
	{
		vec3_free(self->coor);
		vec3_free(self->novec);
		point_free(self->vport);
		free(self);
		self = NULL;
	}
}

static void try_alloc_vport(t_camer *self)
{
	self->vport = point_new();
	if (!self->vport)
	{
		vec3_free(self->coor);
		vec3_free(self->novec);
		free(self);
		self = NULL;
	}
}
static void	try_alloc_novec(t_camer *self)
{
	self->novec = vec3_new();
	if (!self->novec)
	{
		vec3_free(self->coor);
		free(self);
		self = NULL;
	}
}

t_camer	*camer_new(void)
{
	t_camer	*self;

	self = (t_camer *)malloc(sizeof(t_camer));
	if (!self)
		return (NULL);
	self->coor = vec3_new();
	if (!self->coor)
	{
		free(self);
		return (NULL);
	}
	try_alloc_novec(self);
	if (!self)
		return(NULL);
	try_alloc_vport(self);
	if (!self)
		return (NULL);
	try_alloc_cacen(self);
	if (!self)
		return (NULL);
	return (self);
}

void	camer_free(t_camer *self)
{
	if (self->coor)
		vec3_free(self->coor);
	if (self->novec)
		vec3_free(self->novec);
	if (self->vport)
		point_free(self->vport);
	free(self);
}

void	camer_init(t_camer *self)
{
	vec3_init(self->coor);
	vec3_init(self->novec);
	camer_set_fview(self, 0.0);
	camer_set_vport(self, VIEW_PORT_H);
	//camer_set_isize(self, WINDOW_W, ASPECT_RATIO_H / ASPECT_RATIO_W);

}

t_camer	*camer_new_cam(t_vec3 *coor, t_vec3 *novec, double fview, t_point *size)
{
	t_camer	*self;

	self = camer_new();
	camer_set_coord(self, coor);
	camer_set_novec(self, novec);
	camer_set_fview(self, fview);
	camer_calculate_vp_and_pd(self, size);
	camer_calculate_vp_ul(self);
	camer_calculate_pix00(self);
	camer_calculate_background_colors(self);
	camer_set_cacen(self); 
	return (self);
}
