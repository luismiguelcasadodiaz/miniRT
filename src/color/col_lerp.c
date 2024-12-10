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
t_color	col_lerp(t_win *w, t_vec3 *dir)
{
	t_vec3	unit_direction;
	t_color	color;

	col_init_with_1(&color, 0.0, 0.0, 0.0);
	vec3_unit_vector(&unit_direction, dir);
	col_add(&color, &w->camera->color_start, w->ambient->ambient);
	col_create_mlx_color(&color);
	return (color);
}
	//version inicial
	/*t_vec3	aux2;

	//double	a;
	//mlx_color = color.mlx_color;
	// a = 0.5 * (vec3_get_y(&unit_direction) + 1.0);
	// vec3_mul(&color.rgb, &w->camera->color_end.rgb, a);
	// vec3_mul(&aux2, &w->camera->color_start.rgb, (1.0 - a));
	// vec3_add(&color.rgb, &color.rgb, &aux2);
*/
	// version fondo gradiente
	/*t_vec3	unit_direction;
	t_color	color_s;
	double	a;
	t_color	color_e;

	vec3_unit_vector(&unit_direction, dir);
	a = 0.5 * (vec3_get_y(&unit_direction) + 1.0);
	col_scale(&color_e, &w->camera->color_end, a);
	col_scale(&color_s, &w->camera->color_start, (1.0 - a));
	col_add(&color_e, &color_s, &color_e);
	col_add(&color_e, &color_e, w->ambient->ambient);
	return (color_e);*/