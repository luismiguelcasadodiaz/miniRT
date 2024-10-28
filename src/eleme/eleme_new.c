/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:00 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/21 17:21:58 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

static void	try_alloc_coor(t_eleme *self)
{
	self->coor = vec3_new();
	if (!self->coor)
	{
		free(self);
		self = NULL;
	}
}

static void	try_alloc_novec(t_eleme *self)
{
	self->novec = vec3_new();
	if (!self->novec)
	{
		vec3_free(self->coor);
		free(self);
		self = NULL;
	}
}

static void	try_alloc_color(t_eleme *self)
{
	self->color = col_new();
	if (!self->color)
	{
		vec3_free(self->coor);
		vec3_free(self->novec);
		free(self);
		self = NULL;
	}
}

static void	try_alloc_hit(t_eleme *self)
{
	self->hit = malloc(sizeof(t_hitfp));
	if (!self->hit)
	{
		vec3_free(self->coor);
		vec3_free(self->novec);
		col_free(self->color);
		free(self);
		self = NULL;
	}
}

static void try_alloc_u_v(t_eleme *self)
{
	self->u = vec3_new();
	if (!self->u)
	{
		vec3_free(self->coor);
		vec3_free(self->novec);
		col_free(self->color);
		free(self->hit);
		free(self);
		self = NULL;
		return ;
	}
	vec3_init_values(self->u, 0, 0, 0);
	self->v = vec3_new();
	if (!self->v)
	{
		vec3_free(self->coor);
		vec3_free(self->novec);
		col_free(self->color);
		free(self->hit);
		vec3_free(self->u);
		free(self);
		self = NULL;
		return ;
	}
	vec3_init_values(self->v, 0, 0, 0);
}


t_eleme	*eleme_new(void)
{
	t_eleme	*self;

	self = (t_eleme *)malloc(sizeof(t_eleme));
	if (!self)
		return (NULL);
	self->next = NULL;
	self->id = NOELEM;
	try_alloc_coor(self);
	if (self)
		try_alloc_novec(self);
	if (self)
		try_alloc_color(self);
	if (self)
		try_alloc_hit(self);
	if (self)
		try_alloc_u_v(self);		
	return (self);
}
