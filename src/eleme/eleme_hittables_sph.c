/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_hitables_sph.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:40:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 17:11:38 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"
#include "hitrecord.h"

/* a vector dotted with itself is equal to the squared length of that vector
this is te reason why we change the calculation.
      *a = vec3_dot(r->dir, r->dir);
	  *a = vec3_length_squared(r->dir)
and 
	  c = vec3_dot(&oc, &oc) - (radio * radio);
	  c = vec3_length_squared(&oc) - radio ** 2

An additional simplification to calculate the quadratic solution comes wiht a
variable substitution.
let's imaginde b = -2h. 
then what was b = -2d*oc becomes -2h = -2d*oc and h= d*oc

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

static	void	calc_normal(t_eleme *self, t_ray *ray, t_hitrecord *rec)
{
	t_vec3	*normal;

	normal = vec3_new();
	vec3_sub(normal, hitrecord_get_point(rec), eleme_get_coord(self));
	vec3_div(normal, normal, eleme_get_diame(self) / 2);
	hitrecord_face_normal(rec, ray, normal);
	vec3_free(normal);
}

static void	set_hitrecord(t_hitrecord *re, double ro, t_eleme *s, t_ray *ra)
{
	t_point	*p;

	hitrecord_set_t(re, ro);
	p = ray_at(ra, ro);
	hitrecord_set_point(re, p);
	calc_normal(s, ra, re);
	hitrecord_set_hit_obj(re, s);
	point_free(p);
}

bool	hit_sphere(t_hit_args *data)
{
	double	a;
	double	b;
	double	discriminant;
	double	discriminant_root;
	double	root;

	discriminant = calc_discriminant(data->self, data->ray, &a, &b);
	if (discriminant < 0)
		return (false);
	discriminant_root = sqrt(discriminant);
	root = (b - discriminant_root) / a;
	if (!interval_sorrounds(data->ran, root))
	{
		root = (b + discriminant_root) / a;
		if (!interval_sorrounds(data->ran, root))
			return (false);
	}
	set_hitrecord(data->rec, root, data->self, data->ray);
	return (true);
}
