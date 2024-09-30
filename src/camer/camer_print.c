/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:32:35 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/20 21:50:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"
#include <stdio.h>

static char	*translate_e_eleme(enum e_eleme id)
{
	if (id == NOELEM)
		return ("NOELEM");
	if (id == AMBIENT)
		return ("AMBIEMT");
	if (id == CAMERA)
		return ("CAMERA");
	if (id == LIGHT)
		return ("LIGHT");
	if (id == SPHERE)
		return ("SPHERE");
	if (id == PLANE)
		return ("PLANE");
	if (id == CYLINDER)
		return ("CYLINDER");
	return ("NO IDENTIFIED");
}

void	eleme_print(t_eleme	*self)
{
	printf("id                       = %s\n", translate_e_eleme(self->id));
	printf("coor                     = ");
	vec3_print(self->coor);
	printf("novec                    = ");
	vec3_print(self->novec);
	printf("color                    = ");
	col_print(self->color);
	printf("diameter                 = %f\n", self->d);
	printf("height                   = %f\n", self->h);
	printf("Horizontal Field of view = %f\n", self->fview);
	printf("ligth ambient            = %f\n", self->lambi);
	printf("light brightness         = %f\n", self->lbrig);
}
