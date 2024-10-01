/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:32:35 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/01 18:58:56 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"
#include <stdio.h>

void	camer_print(t_camer	*self)
{
	printf("id                       = CAMERA\n");
	printf("coor                     = ");
	vec3_print(self->coor);
	printf("novec                    = ");
	vec3_print(self->novec);
	printf("Horizontal Field of view = %f\n", self->fview);
}
