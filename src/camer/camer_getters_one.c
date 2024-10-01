/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_getters_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:32:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/01 19:02:08 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"

t_vec3	*camer_get_coord(t_camer *self)
{
	return (self->coor);
}

t_vec3	*camer_get_novec(t_camer *self)
{
	return (self->novec);
}

double	camer_get_fview(t_camer *self)
{
	return (self->fview);
}
