/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitrecord_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:33:04 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/13 01:06:02 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitrecord.h"
#include <stdlib.h>

t_hitrecord	*hitrecord_new(void)
{
	t_hitrecord	*self;

	self = (t_hitrecord *)malloc(sizeof(t_hitrecord));
	if (!self)
		return (NULL);
	self->p = point_new();
	if (!self->p)
	{
		free(self);
		return (NULL);
	}
	self->normal = vec3_new();
	if (!self->normal)
	{
		point_free(self->p);
		free(self);
		return (NULL);
	}
	return (self);
}

void	hitrecord_free(t_hitrecord *self)
{
	if (self)
	{
		point_free(self->p);
		vec3_free(self->normal);
		free(self);
	}
}

void	hitrecord_init(t_hitrecord *self)
{
	point_init(self->p, 0.0, 0.0, 0.0);
	vec3_init_values(self->normal, 0.0, 0.0, 0.0);
	self->t = 0.0;
	self->front_face = 0;
	self->hit_obj = NULL;
}

void		hitrecord_copy(t_hitrecord *dest, t_hitrecord *ori)
{
	*dest->p = *ori->p;
	*dest->normal = *ori->normal;
	dest->t = ori->t;
	dest->front_face = ori->front_face;
	*(t_eleme *)dest->hit_obj = *(t_eleme *)ori->hit_obj;
	//*dest->mat = *ori->mat;

}
