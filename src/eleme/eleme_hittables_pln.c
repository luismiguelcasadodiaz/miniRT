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

t_eleme	*eleme_new_pla(t_vec3 *coor, t_vec3 *novec, t_color *rgb255)
{
	t_eleme	*self;

	self = eleme_new();
	eleme_set_ident(self, PLANE);
	eleme_set_coord(self, coor);
	eleme_set_novec(self, novec);
	eleme_set_color(self, rgb255);
	eleme_set_diame(self, 0.0);
	eleme_set_heigh(self, 0.0);
	return (self);
}
