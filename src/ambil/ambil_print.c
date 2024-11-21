/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambil_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:32:35 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/30 20:07:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambil.h"
#include <stdio.h>

void	ambil_print(t_ambil	*self)
{
	printf("-------------------------------------------\n");
	printf("id                       = AMBIL\n");
	printf("Ambient light color      = ");
	col_print(self->color);
	printf("Ambient light ratio      = %f\n", self->lambi);
	printf("Ambient light            = ");
	col_print(self->ambient);
}
