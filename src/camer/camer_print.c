/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:32:35 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/08 00:17:23 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"
#include <stdio.h>

void	camer_print(t_camer	*self)
{
	printf("-------------------------------------------\n");
	printf("id                       = CAMERA\n");
	printf("coor                     = ");
	vec3_print(self->coor);
	printf("novec                    = ");
	vec3_print(self->novec);
	printf("Horizontal Field of view = %f\n", self->fview);
	printf("Viewport                 = ");
	point_print(self->vport);
	printf("camera center            = ");
	point_print(self->cacen);
	printf("vp_x                     = ");
	vec3_print(self->vp_x);
	printf("vp_y                     = ");
	vec3_print(self->vp_y);
	printf("pd_x                     = ");
	vec3_print(self->pd_x);
	printf("pd_x                     = ");
	vec3_print(self->pd_x);
	printf("vp_ul                    = ");
	vec3_print(self->vp_ul);
	printf("pixel00                  = ");
	vec3_print(self->pixel00);
}
