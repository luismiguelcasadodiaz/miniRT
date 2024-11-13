/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_setters_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:04 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/13 18:13:15 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	*light_set(t_vec3 *coor, double lbrig)
{
	t_light	*self;

	self = light_new();
	light_set_coord(self, coor);
	light_set_lbrig(self, lbrig);
	self->next = NULL;
	return (self);
}

t_light	*light_set_bonus(t_vec3 *coor, double lbrig, t_color *rgb255)
{
	t_light	*self;

	self = light_new();
	light_set_coord(self, coor);
	light_set_lbrig(self, lbrig);
	light_set_color(self, rgb255);
	self->next = NULL;
	return (self);
}

void	light_set_coord(t_light *self, t_vec3 *coor)
{
	vec3_copy_values(self->coor, coor);
}

void	light_set_color(t_light *self, t_color *color)
{
	col_copy_values(self->color, color);
}

void	light_set_lbrig(t_light *self, double lbrig)
{
	self->lbrig = lbrig;
}
