/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:32:35 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/30 20:06:53 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include <stdio.h>

void	light_print(t_light	*self)
{
	while (self != NULL)
	{
		printf("-------------------------------------------\n");
		printf("id                       = LIGHT\n");
		printf("coor                     = ");
		vec3_print(self->coor);
		printf("color                    = ");
		col_print(self->color);
		printf("light brightness         = %f\n", self->lbrig);
		if (self->next != NULL)
			light_print(self->next);
		break ;
	}
}
