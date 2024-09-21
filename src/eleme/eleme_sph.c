/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:40:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/21 10:01:44 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

t_eleme	*eleme_new_sph(t_vec3 *coor, double d, t_color *rgb255)
{
	t_eleme	*self;

	self = eleme_new();
	eleme_set_ident(self, SPHERE);
	eleme_set_coord(self, coor);
	eleme_set_diame(self, d);
	eleme_set_color(self, rgb255);
	return (self);
}
