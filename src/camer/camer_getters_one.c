/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_getters_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:32:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/20 20:23:03 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

enum e_eleme	eleme_get_ident(t_eleme *self)
{
	return (self->id);
}

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

double	eleme_get_diame(t_eleme *self)
{
	return (self->d);
}
