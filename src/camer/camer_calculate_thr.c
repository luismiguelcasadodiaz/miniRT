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

void	camer_calc_w(t_camer *self)
{
	t_vec3	aux;

	//vec3_sub(&aux, &self->lookfrom, &self->lookat);
	//vec3_unit_vector(&self->w, &aux);
	vec3_unit_vector(&aux, &self->novec);
	vec3_negate(&self->w, &aux);

}

void	camer_calc_u(t_camer *self)
{
	t_vec3	aux;

	vec3_cross(&aux, &self->vup, &self->w);
	vec3_unit_vector(&self->u, &aux);
}

void	camer_calc_v(t_camer *self)
{
	vec3_cross(&self->v, &self->w, &self->u);
}

void	camer_calc_viewport_u(t_camer *self)
{
	vec3_mul(&self->vp_u, &self->u, self->viewport_width);
}

void	camer_calc_viewport_v(t_camer *self)
{
	t_vec3	aux;

	vec3_negate(&aux, &self->v);
	vec3_mul(&self->vp_v, &aux, self->viewport_height);
}
