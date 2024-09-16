/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:09:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/13 07:39:30 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include <stdlib.h>

t_point	*point_new(void)
{
	t_point	*self;

	self = (t_point *)malloc(sizeof(t_point));
	if (!self)
		return (NULL);
	self->x = 0;
	self->y = 0;
	self->z = 0;
	return (self);
}

void	point_free(t_point *self)
{
	free(self);
}

void	point_init(t_point *self, double the_x, double the_y, double the_z)
{
	self->x = the_x;
	self->y = the_y;
	self->z = the_z;
}
