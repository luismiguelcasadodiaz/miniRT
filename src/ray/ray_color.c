/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:11:26 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/21 12:13:30 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "eleme.h"

static int	hit_sphere(t_eleme *o, t_ray *r)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	radio;

	radio = o->d / 2.0;
	oc.e[0] = o->coor->e[0] - r->orig->x;
	oc.e[1] = o->coor->e[1] - r->orig->y;
	oc.e[2] = o->coor->e[2] - r->orig->z;
	a = vec3_dot(r->dir, r->dir);
	b = vec3_dot(r->dir, &oc) * -2.0;
	c = vec3_dot(&oc, &oc) - (radio * radio);
	return ((((b * b) - (4 * a * c)) >= 0));
}

int	ray_color(t_ray	*self, t_color color_start, t_color color_end, t_eleme *o)
{
	int		mlx_color;

	if (hit_sphere(o, self))
		return (o->color->mlx_color);
	mlx_color = col_lerp(&color_start, &color_end, self->dir);
	return (mlx_color);
}
