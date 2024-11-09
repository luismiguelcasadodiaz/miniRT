/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_setters_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:04 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/30 20:09:23 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

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

void	light_add(t_light **self, t_light *new)
{
	if (*self == NULL)
		*self = new;
	else
	{
		new->next = *self;
		*self = new;
	}
}