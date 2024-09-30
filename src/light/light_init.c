/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:00 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/30 20:14:01 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

static void	try_alloc_color(t_light *self)
{
	self->color = col_new();
	if (!self->color)
	{
		vec3_free(self->coor);
		free(self);
		self = NULL;
	}
}

t_light	*light_new(void)
{
	t_light	*self;

	self = (t_light *)malloc(sizeof(t_light));
	if (!self)
		return (NULL);
	self->coor = vec3_new();
	if (!self->coor)
	{
		free(self);
		return (NULL);
	}
	try_alloc_color(self);
	return (self);
}

void	light_free(t_light *self)
{
	if (self->coor)
		vec3_free(self->coor);
	if (self->color)
		col_free(self->color);
	free(self);
}

void	light_init(t_light *self)
{
	vec3_init(self->coor);
	col_init_with_1(self->color, 0.0, 0.0, 0.0);
	light_set_lbrig(self, 0.0);
}

t_light	*light_new_lig(t_vec3 *coor, double lbrig, t_color *rgb255)
{
	t_light	*self;

	self = light_new();
	light_set_coord(self, coor);
	light_set_lbrig(self, lbrig);
	light_set_color(self, rgb255);
	return (self);
}
