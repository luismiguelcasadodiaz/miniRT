/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:27:47 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/25 20:29:06 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_point	*ray_at(t_ray *self, double t)
{
	t_point *t_times_dir;

	t_times_dir = point_new();
	vec3_scale(t_times_dir, self->dir, t);
	vec3_add(t_times_dir, self->orig, t_times_dir);
	return t_times_dir;
}
