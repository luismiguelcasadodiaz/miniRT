/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitrecord_setters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:16:02 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/13 01:00:48 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitrecord.h"

void	hitrecord_set_point(t_hitrecord *self, t_point *the_p)
{
	point_copy_values(self->p, the_p);
}

void	hitrecord_set_normal(t_hitrecord *self, t_vec3 *the_normal)
{
	vec3_copy_values(self->normal, the_normal);
}

void	hitrecord_set_t(t_hitrecord *self, double the_t)
{
	self->t = the_t;
}

void	hitrecord_set_front_face(t_hitrecord *self, int the_front_face)
{
	self->front_face = the_front_face;
}

void	hitrecord_set_hit_obj(t_hitrecord *self, void *the_hit_obj)
{
	self->hit_obj = the_hit_obj;
}
