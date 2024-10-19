/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:00 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/01 19:24:09 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

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

static void try_alloc_hit(t_eleme * self)
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

t_eleme	*eleme_new(void)
{
	t_eleme	*self;

	self = (t_eleme *)malloc(sizeof(t_eleme));
	if (!self)
		return (NULL);
	self->id = NOELEM;
	self->coor = vec3_new();
	if (!self->coor)
	{
		free(self);
		return (NULL);
	}
	try_alloc_novec(self);
	try_alloc_color(self);
	try_alloc_hit(self);
	return (self);
}

void	eleme_free(t_eleme *self)
{
	if (self->coor)
		vec3_free(self->coor);
	if (self->novec)
		vec3_free(self->novec);
	if (self->color)
		col_free(self->color);
	if (self->hit)
		free(self->hit);
	free(self);
}

void	eleme_init(t_eleme *self)
{
	eleme_set_ident(self, NOELEM);
	vec3_init(self->coor);
	vec3_init(self->novec);
	col_init_with_1(self->color, 0.0, 0.0, 0.0);
	eleme_set_diame(self, 0.0);
	eleme_set_heigh(self, 0.0);
}
