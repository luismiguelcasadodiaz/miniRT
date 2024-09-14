/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 07:52:52 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/13 15:09:34 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "point.h"
#include "vec3.h"
#include <stdlib.h>

t_ray	*ray_new(void)
{
	t_ray	*self;

	self = (t_ray *)malloc(sizeof(t_ray));
	if (!self)
		return (NULL);
	self->orig = point_new();
	if (!self->orig)
	{
		free(self);
		return (NULL);
	}
	self->dir = vec3_new();
	if (!self->dir)
	{
		point_free(self->orig);
		free(self);
		return (NULL);
	}
	return (self);
}

void	ray_init(t_ray *self, t_point *the_orig, t_vec3 *the_dir)
{
	self->orig = the_orig;
	self->dir = the_dir;
}

void	ray_free(t_ray *self)
{
	free(self);
}
