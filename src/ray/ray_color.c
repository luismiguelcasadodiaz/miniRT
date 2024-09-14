/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:11:26 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/14 10:56:45 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int	ray_color(t_ray	*self)
{
	t_color	*start;
	t_color	*end;
	int		mlx_color;

	start = col_new();
	end = col_new();
	col_init_with_1(start, 1.0, 1.0, 1.0);
	col_init_with_1(end, 0.5, 0.7, 1.0);
	mlx_color = col_lerp(start, end, self->dir);
	free(start);
	free(end);
	return (mlx_color);
}
