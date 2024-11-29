/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_setters_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:04 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/01 19:21:04 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

void	eleme_set_ident(t_eleme *self, enum e_eleme id)
{
	self->id = id;
}

void	eleme_set_diame(t_eleme *self, double d)
{
	self->d = d;
}

void	eleme_set_heigh(t_eleme *self, double h)
{
	self->h = h;
}

void	eleme_set_hit(t_eleme *self, t_hitfp func)
{
	*self->hit = *func;
}

void	eleme_set_w(t_eleme *self, t_vec3 *w)
{
	vec3_copy_values(self->w, w);
}
