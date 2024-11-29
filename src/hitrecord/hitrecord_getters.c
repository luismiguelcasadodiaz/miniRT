/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitrecord_getters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:18:11 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/12 21:26:42 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitrecord.h"

t_point	*hitrecord_get_point(t_hitrecord *self)
{
	return (self->p);
}

t_vec3	*hitrecord_get_normal(t_hitrecord *self)
{
	return (self->normal);
}

double	hitrecord_get_t(t_hitrecord *self)
{
	return (self->t);
}

int	hitrecord_get_front_face(t_hitrecord *self)
{
	return (self->front_face);
}

void	*hitrecord_get_hit_obj(t_hitrecord *self)
{
	return (self->hit_obj);
}
