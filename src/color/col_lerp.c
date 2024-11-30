/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_lerp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:16:19 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/16 16:12:33 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "miniRT.h"

//int	col_lerp(t_color *start, t_color *end, t_vec3 *dir)
int	col_lerp(t_win *w, t_vec3 *dir)
{
	t_vec3	unit_direction;
	t_color	color;
	int		mlx_color;

	col_init_with_1(&color, 0.0, 0.0, 0.0);
	vec3_unit_vector(&unit_direction, dir);
	col_add(&color, &w->camera->color_start, w->ambient->ambient);
	col_create_mlx_color(&color);
	mlx_color = color.mlx_color;
	return (mlx_color);
}
	//t_vec3	aux2;
	//double	a;
	// a = 0.5 * (vec3_get_y(&unit_direction) + 1.0);
	// vec3_mul(&color.rgb, &w->camera->color_end.rgb, a);
	// vec3_mul(&aux2, &w->camera->color_start.rgb, (1.0 - a));
	// vec3_add(&color.rgb, &color.rgb, &aux2);