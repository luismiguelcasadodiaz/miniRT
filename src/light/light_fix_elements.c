/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_fix_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:40:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/21 13:11:53 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

t_eleme	*eleme_new_amb(double lambi, t_color *rgb255)
{
	t_eleme	*self;

	self = eleme_new();
	eleme_set_ident(self, AMBIENT);
	eleme_set_lambi(self, lambi);
	eleme_set_color(self, rgb255);
	return (self);
}

t_eleme	*eleme_new_cam(t_vec3 *coor, t_vec3 *novec, double fview)
{
	t_eleme	*self;

	self = eleme_new();
	eleme_set_ident(self, CAMERA);
	eleme_set_coord(self, coor);
	eleme_set_novec(self, novec);
	eleme_set_fview(self, fview);
	return (self);
}

t_eleme	*eleme_new_lig(t_vec3 *coor, double lbrig, t_color *rgb255)
{
	t_eleme	*self;

	self = eleme_new();
	eleme_set_ident(self, LIGHT);
	eleme_set_coord(self, coor);
	eleme_set_lbrig(self, lbrig);
	eleme_set_color(self, rgb255);
	return (self);
}
