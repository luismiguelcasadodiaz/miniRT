/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_hitables_pla.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:40:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 12:19:52 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

static void	try_alloc(t_eleme **self, t_vec3 **u, t_vec3 **v)
{
	*self = eleme_new();
	if (self)
	{
		*u = vec3_new();
		if (!u)
		{
			eleme_free(*self);
			*self = NULL;
		}
		*v = vec3_new();
		if (!v)
		{
			vec3_free(*u);
			eleme_free(*self);
			*self = NULL;
		}
	}
}

t_eleme	*eleme_new_pla(t_vec3 *coor, t_vec3 *novec, t_color *rgb255)
{
	t_eleme	*self;
	t_vec3	*u;
	t_vec3	*v;

	try_alloc(&self, &u, &v);
	vec3_u_v_from_n(novec, u, v);
	eleme_set_ident(self, PLANE);
	eleme_set_coord(self, coor);
	eleme_set_novec(self, novec);
	eleme_set_color(self, rgb255);
	eleme_set_diame(self, 0.0);
	eleme_set_heigh(self, 0.0);
	eleme_set_u(self, u);
	eleme_set_v(self, v);
	vec3_free(u);
	vec3_free(v);
	return (self);
}
