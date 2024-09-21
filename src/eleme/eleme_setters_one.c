/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_setters_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:04 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/20 20:37:16 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

void	eleme_set_ident(t_eleme *self, enum e_eleme id)
{
	self->id = id;
}

void	eleme_set_coord(t_eleme *self, t_vec3 *coor)
{
	vec3_copy_values(self->coor, coor);
}

void	eleme_set_novec(t_eleme *self, t_vec3 *novec)
{
	vec3_copy_values(self->novec, novec);
}

void	eleme_set_color(t_eleme *self, t_color *color)
{
	col_copy_values(self->color, color);
}

void	eleme_set_diame(t_eleme *self, double d)
{
	self->d = d;
}
