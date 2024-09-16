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

int	col_lerp(t_color *start, t_color *end, t_vec3 *dir)
{
	t_vec3	unit_direction;
	t_color	*color;
	t_vec3	aux2;
	double	a;
	int		mlx_color;

	color = col_new();
	col_init_with_1(color, 0.0, 0.0, 0.0);
	vec3_unit_vector(&unit_direction, dir);
	a = 0.5 * (vec3_get_y(&unit_direction) + 1.0);
	vec3_mul(color->rgb, end->rgb, a);
	vec3_mul(&aux2, start->rgb, (1.0 - a));
	vec3_add(color->rgb, color->rgb, &aux2);
	color->t = 0;
	col_create_mlx_color(color);
	mlx_color = color->mlx_color;
	col_free(color);
	return (mlx_color);
}
