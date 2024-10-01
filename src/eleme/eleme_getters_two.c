/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_getters_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:32:53 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/01 19:22:26 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

t_vec3	*eleme_get_coord(t_eleme *self)
{
	return (self->coor);
}

t_vec3	*eleme_get_novec(t_eleme *self)
{
	return (self->novec);
}

t_color	*eleme_get_color(t_eleme *self)
{
	return (self->color);
}
