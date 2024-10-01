/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:00 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/01 19:27:44 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"

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
	return (self);
}

void	camer_free(t_camer *self)
{
	if (self->coor)
		vec3_free(self->coor);
	if (self->novec)
		vec3_free(self->novec);
	free(self);
}

void	camer_init(t_camer *self)
{
	vec3_init(self->coor);
	vec3_init(self->novec);
	camer_set_fview(self, 0.0);
}

t_camer	*camer_new_cam(t_vec3 *coor, t_vec3 *novec, double fview)
{
	t_camer	*self;

	self = camer_new();
	camer_set_coord(self, coor);
	camer_set_novec(self, novec);
	camer_set_fview(self, fview);
	return (self);
}
