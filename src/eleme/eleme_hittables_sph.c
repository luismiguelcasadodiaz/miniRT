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
}

bool	hit_sphere(t_eleme *slf, t_ray *ray, t_interval *ran, t_hitrecord *rec)
{
	double	a;
	double	b;
	double	discriminant;
	double	discriminant_root;
	double	root;

	discriminant = calc_discriminant(slf, ray, &a, &b);
	if (discriminant < 0)
		return (false);
	discriminant_root = sqrt(discriminant);
	root = (b - discriminant_root) / a;
	if (!interval_sorrounds(ran, root))
	{
		root = (b + discriminant_root) / a;
		if (!interval_sorrounds(ran, root))
			return (false);
	}
	hitrecord_set_t(rec, root);
	hitrecord_set_point(rec, ray_at(ray, root));
	calc_normal(slf, ray, rec);
	hitrecord_set_hit_obj(rec, slf);
	return (true);
}

t_eleme	*eleme_new_sph(t_vec3 *coor, double d, t_color *rgb255)
{
	t_eleme	*self;
	t_vec3	*novec;

	self = eleme_new();
	eleme_set_ident(self, SPHERE);
	eleme_set_coord(self, coor);
	novec = vec3_new();
	vec3_init_values(novec, 0, 0, 0);
	eleme_set_novec(self, novec);
	vec3_free(novec);
	eleme_set_color(self, rgb255);
	eleme_set_diame(self, d);
	eleme_set_heigh(self, 0.0);
	eleme_set_hit(self, hit_sphere);
	return (self);
}
