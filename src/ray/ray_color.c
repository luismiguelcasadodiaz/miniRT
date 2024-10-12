/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:11:26 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/08 00:23:09 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "eleme.h"
#include <math.h>
/* a vector dotted with itself is equal to the squared length of that vector
this is te reason why we change the calculation.
      *a = vec3_dot(r->dir, r->dir);
	  *a = vec3_length_squared(r->dir)
and 
	  c = vec3_dot(&oc, &oc) - (radio * radio);
	  c = vec3_length_squared(&oc) - radio ** 2

An additional simplification to calculate the quadratic solution comes wiht a variable substitution .
let's imaginde b = -2h. then waht was b = -2d*oc becomes -2h = -2d*oc and h= d*oc

*/
static double	calc_discriminant(t_eleme *o, t_ray *r, double *a, double *b)
{
	double	c;
	t_vec3	oc;
	double	radio;

	radio = o->d / 2.0;
	vec3_sub(&oc, o->coor, r->orig);
	*a = vec3_length_squared(r->dir);
	*b = vec3_dot(r->dir, &oc);
	c = vec3_length_squared(&oc) - (radio * radio);
	return (((*b * *b) - (*a * c)));
}

static double	hit_sphere(t_eleme *o, t_ray *r)
{
	double	a;
	double	b;
	double	discriminant;

	discriminant = calc_discriminant(o, r, &a, &b);
	if (discriminant < 0)
		return (-1.0);
	else
		return (((b - sqrt(discriminant)) / a));
}

static	t_vec3	*get_normal(t_ray *self, double t)
{
	t_vec3	*vec3_0_0_minus1;
	t_vec3	*ray_at_t;
	t_vec3	*normal;

	vec3_0_0_minus1 = vec3_new();
	vec3_init_values(vec3_0_0_minus1, 0, 0, -1);
	ray_at_t = ray_at(self, t);
	vec3_sub(ray_at_t, ray_at_t, vec3_0_0_minus1);
	normal = vec3_new();
	vec3_unit_vector(normal, ray_at_t);
	vec3_free(ray_at_t);
	vec3_free(vec3_0_0_minus1);
	return (normal);
}

int	ray_color(t_ray	*self, t_color color_start, t_color color_end, t_eleme *o)
{
	int		mlx_color;
	double	t;
	t_vec3	*normal;
	t_color	*normalized_color;

	t = hit_sphere(o, self);
	if (t > 0.0)
	{
		normal = get_normal(self, t);
		normalized_color = col_new();
		col_init_with_1(normalized_color, 0.5 * (1 + vec3_get_x(normal)),
			0.5 * (1 + vec3_get_y(normal)), 0.5 * (1 + vec3_get_z(normal)));
		//col_init_with_1(normalized_color, 1, 0, 0);
		mlx_color = col_get_mlx_color(normalized_color);
		//vec3_print(normalized_color->rgb);
		vec3_free(normal);
		col_free(normalized_color);
	}
	else
		mlx_color = col_lerp(&color_start, &color_end, self->dir);
	return (mlx_color);
}
