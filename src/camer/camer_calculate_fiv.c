/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_calculate_vp_ul.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:09:47 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/13 20:43:17 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"
#include <math.h>

void	camer_calc_defocus_disk_u(t_camer *self)
{
	vec3_mul(self->defocus_disk_u, self->u, self->defocus_radius);
}

void	camer_calc_defocus_disk_v(t_camer *self)
{
	vec3_mul(self->defocus_disk_v, self->v, self->defocus_radius);
}
