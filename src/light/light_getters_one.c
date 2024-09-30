/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_getters_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:32:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/30 20:10:45 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_vec3	*light_get_coord(t_light *self)
{
	return (self->coor);
}

t_color	*light_get_color(t_light *self)
{
	return (self->color);
}

double	light_get_lbrig(t_light *self)
{
	return (self->lbrig);
}
