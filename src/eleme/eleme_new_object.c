/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_new_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:18:14 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/05 17:39:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "eleme.h"

t_eleme	*eleme_new_sph(t_vec3 *coor, double d, t_color *rgb255)
{
	t_eleme	*self;
	t_vec3	*novec;

	self = eleme_new();
	if (!self)
		return (NULL);
	novec = vec3_new();
	if (!novec)
	{
		eleme_free(self);
		return (NULL);
	}
	vec3_init_values(novec, 0, 0, 0);
	eleme_set_ident(self, SPHERE);
	eleme_set_coord(self, coor);
	eleme_set_novec(self, novec);
	eleme_set_color(self, rgb255);
	eleme_set_diame(self, d);
	eleme_set_heigh(self, 0.0);
	eleme_set_hit(self, hit_sphere);
	vec3_free(novec);
	return (self);
}

t_eleme	*eleme_new_pla(t_vec3 *coor, t_vec3 *novec, t_color *rgb255)
{
	t_eleme	*self;

	self = eleme_new();
	if (!self)
		return (NULL);
	vec3_u_v_from_n(novec, self->u, self->v);
	eleme_set_ident(self, PLANE);
	eleme_set_coord(self, coor);
	eleme_set_novec(self, novec);
	eleme_set_color(self, rgb255);
	eleme_set_diame(self, 0.0);
	eleme_set_heigh(self, 0.0);
	eleme_set_hit(self, hit_plane);
	return (self);
}

t_eleme	*eleme_new_cyl(t_vec3 *coor, t_vec3 *novec, t_vec3 *d, t_color *rgb255)
{
	t_eleme	*self;

	self = eleme_new();
	eleme_set_ident(self, CYLINDER);
	eleme_set_coord(self, coor);
	eleme_set_novec(self, novec);
	eleme_set_color(self, rgb255);
	eleme_set_diame(self, vec3_get_x(d));
	eleme_set_heigh(self, vec3_get_y(d));
	eleme_set_hit(self, hit_cyl);
	return (self);
}
