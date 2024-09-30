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
	printf("id                       = AMBIL\n");
	printf("color                    = ");
	col_print(self->color);
	printf("ligth ambient            = %f\n", self->lambi);
}
