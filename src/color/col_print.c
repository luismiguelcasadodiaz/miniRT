/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:01:18 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/08 16:56:50 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdio.h>

void	col_print(t_color *self)
{
	vec3_print(self->rgb);
	printf(" mlx_color = %d ", self->mlx_color);
	printf("transparency = %d ", self->t);
}
