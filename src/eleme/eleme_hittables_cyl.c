/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_hitables_cyl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:40:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 12:18:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

// t_vec3 *d holds diameter in x, and height in y. 42 norm restrictions !!!!
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
	return (self);
}
