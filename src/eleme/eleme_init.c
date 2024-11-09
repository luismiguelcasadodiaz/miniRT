/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:00 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/21 17:26:34 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

void	eleme_init(t_eleme *self)
{
	eleme_set_ident(self, NOELEM);
	vec3_init(self->coor);
	vec3_init(self->novec);
	col_init_with_1(self->color, 0.0, 0.0, 0.0);
	eleme_set_diame(self, 0.0);
	eleme_set_heigh(self, 0.0);
}

void	eleme_free(t_eleme *self)
{
	while (self)
	{
		if (self->coor)
			vec3_free(self->coor);
		if (self->novec)
			vec3_free(self->novec);
		if (self->color)
			col_free(self->color);
		if (self->hit)
			free(self->hit);
		if (self->u)
			vec3_free(self->u);
		if (self->v)
			vec3_free(self->v);
		if (self->w)
			vec3_free(self->w);
		if (self->next)
			eleme_free(self->next);
		break ;
	}
	free(self);
}

void	eleme_add(t_eleme **self, t_eleme *new)
{
	if (*self == NULL)
		*self = new;
	else
	{
		new->next = *self;
		*self = new;
	}
}


