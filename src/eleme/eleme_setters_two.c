/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_setters_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:09 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/01 19:19:53 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

void	eleme_set_coord(t_eleme *self, t_vec3 *coor)
{
	vec3_copy_values(self->coor, coor);
}

// known the normal, calculates w.
void	eleme_set_novec(t_eleme *self, t_vec3 *novec)
{
	double	n_dot_n;
	t_vec3	*w;

	vec3_copy_values(self->novec, novec);
	if (!vec3_iszero(novec))
	{
		n_dot_n = vec3_dot(novec, novec);
		w = vec3_new();
		if (w)
		{
			vec3_scale(w, novec, 1.0 / n_dot_n);
			eleme_set_w(self, w);
			vec3_free(w);
		}
	}
}

void	eleme_set_color(t_eleme *self, t_color *color)
{
	col_copy_values(self->color, color);
}

void	eleme_set_u(t_eleme *self, t_vec3 *u)
{
	vec3_copy_values(self->u, u);
}

void	eleme_set_v(t_eleme *self, t_vec3 *v)
{
	vec3_copy_values(self->v, v);
}
