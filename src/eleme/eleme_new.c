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

static void	try_alloc_coor_u(t_eleme *self)
{
	self->coor = vec3_new();
	if (!self->coor)
	{
		free(self);
		self = NULL;
	}
	self->u = vec3_new();
	if (!self->u)
	{
		vec3_free(self->coor);
		free(self);
		self = NULL;
		return ;
	}
	vec3_init_values(self->u, 0, 0, 0);
}

static void	try_alloc_novec_w(t_eleme *self)
{
	self->novec = vec3_new();
	if (!self->novec)
	{
		vec3_free(self->coor);
		vec3_free(self->u);
		free(self);
		self = NULL;
	}
	self->w = vec3_new();
	if (!self->w)
	{
		vec3_free(self->coor);
		vec3_free(self->u);
		vec3_free(self->novec);
		free(self);
		self = NULL;
	}
	vec3_init_values(self->novec, 0, 0, 0);
	vec3_init_values(self->w, 0, 0, 0);
}

static void	try_alloc_color_v(t_eleme *self)
{
	self->color = col_new();
	if (!self->color)
	{
		vec3_free(self->coor);
		vec3_free(self->u);
		vec3_free(self->novec);
		vec3_free(self->w);
		free(self);
		self = NULL;
	}
	col_init_with_1(self->color, 0, 0, 0);
	self->v = vec3_new();
	if (!self->v)
	{
		vec3_free(self->coor);
		vec3_free(self->u);
		vec3_free(self->novec);
		vec3_free(self->w);
		col_free(self->color);
		free(self);
		self = NULL;
		return ;
	}
	vec3_init_values(self->v, 0, 0, 0);
}

static void	try_alloc_hit(t_eleme *self)
{
	self->hit = malloc(sizeof(t_hitfp));
	if (!self->hit)
	{
		vec3_free(self->coor);
		vec3_free(self->u);
		vec3_free(self->novec);
		vec3_free(self->w);
		col_free(self->color);
		vec3_free(self->v);
		free(self);
		self = NULL;
	}
}

t_eleme	*eleme_new(void)
{
	t_eleme	*self;

	self = (t_eleme *)malloc(sizeof(t_eleme));
	if (!self)
		return (NULL);
	self->next = NULL;
	self->id = NOELEM;
	try_alloc_coor_u(self);
	if (self)
		try_alloc_novec_w(self);
	if (self)
		try_alloc_color_v(self);
	if (self)
		try_alloc_hit(self);
	return (self);
}
