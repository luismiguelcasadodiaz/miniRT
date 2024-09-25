/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:11:26 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/25 19:57:28 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "eleme.h"
#include <math.h>

static int	hit_sphere(t_eleme *o, t_ray *r)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	radio;
	double	discriminant;

	radio = o->d / 2.0;
	vec3_sub(&oc, o->coor, r->orig);
	a = vec3_dot(r->dir, r->dir);
	b = vec3_dot(r->dir, &oc) * -2.0;
	c = vec3_dot(&oc, &oc) - (radio * radio);
	discriminant = (((b * b) - (4 * a * c)) >= 0);
	if (discriminant < 0)
		return (-1.0);
	else
		return (((-b - sqrt(discriminant)) / (2.0 * a)));
}

static	t_vec3	*get_normal(t_ray *self, double t)
{
	t_vec3	vec3_0_0_minus1;
	t_vec3	*ray_at_t;
	t_vec3	*normal;

	vec3_init_values(&vec3_0_0_minus1, 0, 0, -1);
	ray_at_t = ray_at(self, t);
	vec3_sub(ray_at_t, ray_at_t, &vec3_0_0_minus1);
	normal = vec3_new();
	vec3_free(ray_at_t);
	vec3_unit_vector(normal, ray_at_t);
	return normal;
}

int	ray_color(t_ray	*self, t_color color_start, t_color color_end, t_eleme *o)
{
	int		mlx_color;
	double	t;
	t_vec3	*normal;
	t_color normalized_color;

	t = hit_sphere(o, self);

	if (t > 0.0)
	{
		normal = get_normal(self, t);
		col_init_with_1(&normalized_color, 0.5 * vec3_get_x(normal),
				0.5 * vec3_get_y(normal), 0.5 * vec3_get_z(normal));
		vec3_free(normal);
		return (col_get_mlx_color(&normalized_color));
	}
	mlx_color = col_lerp(&color_start, &color_end, self->dir);
	return (mlx_color);
}
