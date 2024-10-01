/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_setters_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:04 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/01 19:03:58 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"

void	camer_set_coord(t_camer *self, t_vec3 *coor)
{
	vec3_copy_values(self->coor, coor);
}

void	camer_set_novec(t_camer *self, t_vec3 *novec)
{
	vec3_copy_values(self->novec, novec);
}

void	camer_set_fview(t_camer *self, double fview)
{
	self->fview = fview;
}
