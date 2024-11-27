/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:56:33 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/27 20:03:30 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "color.h"

void	col_add(t_color *result, t_color *c1, t_color *c2)
{
	result->rgb.e[0] = c1->rgb.e[0] + c2->rgb.e[0];
	if (result->rgb.e[0] > 1)
		result->rgb.e[0] = 1;
	result->rgb.e[1] = c1->rgb.e[1] + c2->rgb.e[1];
	if (result->rgb.e[1] > 1)
		result->rgb.e[1] = 1;
	result->rgb.e[2] = c1->rgb.e[2] + c2->rgb.e[2];
	if (result->rgb.e[2] > 1)
		result->rgb.e[2] = 1;
	col_create_mlx_color(result);
}

void	col_scale(t_color *result, t_color *c1, double scale)
{
	result->rgb.e[0] = c1->rgb.e[0] * scale;
	if (result->rgb.e[0] > 1)
		result->rgb.e[0] = 1;
	result->rgb.e[1] = c1->rgb.e[1] * scale;
	if (result->rgb.e[1] > 1)
		result->rgb.e[1] = 1;
	result->rgb.e[2] = c1->rgb.e[2] * scale;
	if (result->rgb.e[2] > 1)
		result->rgb.e[2] = 1;
	col_create_mlx_color(result);
}
