/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_hitables_pla.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:40:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 12:19:52 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"
#include "hitrecord.h"
#include <math.h>
#include <stdbool.h>
// when (alpha < 0 || alpha > 1 || beta < 0 || beta > 1)
// the ray intersected the infinite plane outside de square
/*
static bool	alfa_beta(t_eleme *self, t_vec3 *a, t_vec3 *b)
{
	double	alpha;
	double	beta;

	alpha = vec3_dot(eleme_get_w(self), a);
	beta = vec3_dot(eleme_get_w(self), b);
	if (alpha < 0 || alpha > 1 || beta < 0 || beta > 1)
		return (false);
	return (true);
}
*/
/*
static bool	lies_within_planar_shape(t_eleme *self, t_point *p)
{
	t_vec3	pq;
	t_vec3	a;
	t_vec3	b;

	vec3_sub(&pq, p, self->coor);
	vec3_cross(&a, &pq, self->v);
	vec3_cross(&b, self->u, &pq);
	return (alfa_beta(self, &a, &b));
}
*/
//the ray orig + dir * t, hits de plane when a ray point dotted wiht plane 
// normal equals D, being plane formula Ax + By + Cz = D
// n dot (orig + dir * t) = d, solved for t gives the impact point.
// denom if zero means the ray is parallet to plane
// we consider that is pararalel if < 0.00000001
// d comes form novec (normal) dotted with coor(point in plane)
// t, the distance to the impact point has to be inside de interval ran
// p is the impact point at t distance
bool	hit_plane(t_hit_args *data)
{
	double	denom;
	double	d;
	double	t;
	t_point	*p;

	denom = vec3_dot(data->self->novec, data->ray->dir);
	if (fabs(denom) < 1e-8)
		return (false);
	d = vec3_dot(data->self->novec, data->self->coor);
	t = (d - vec3_dot(data->self->novec, data->ray->orig)) / denom;
	if (!int_contains(data->ran, t))
		return (false);
	p = ray_at(data->ray, t);
	hitrecord_set_t(data->rec, t);
	hitrecord_set_point(data->rec, p);
	point_free(p);
	hitrecord_set_hit_obj(data->rec, data->self);
	hitrecord_face_normal(data->rec, data->ray, data->self->novec);
	return (true);
}
	//p = ray_at(data->ray, t);
	//if (!lies_within_planar_shape(self, p))
	//{
	//	point_free(p);
	//	return (false);
	//}
