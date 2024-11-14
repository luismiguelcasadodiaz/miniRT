/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:33:23 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/03 20:34:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"
/*
static void	try_alloc_cacen(t_camer *self)
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

static void	try_alloc_vport(t_camer *self)
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
*/
t_camer	*camer_new(void)
{
	t_camer	*self;

	self = (t_camer *)malloc(sizeof(t_camer));
	if (!self)
		return (NULL);
	/*
	self->coor = vec3_new();
	if (!self->coor)
	{
		free(self);
		return (NULL);
	}
	try_alloc_novec(self);
	if (!self)
		return (NULL);
	try_alloc_vport(self);
	if (!self)
		return (NULL);
	try_alloc_cacen(self);
	if (!self)
		return (NULL);
		*/
	return (self);
}
