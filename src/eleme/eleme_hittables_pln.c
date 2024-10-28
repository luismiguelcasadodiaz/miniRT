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

static bool lies_within_planar_shape(t_eleme *self, t_point *p)
{
	t_vec3	pq;
	t_vec3	a;
	t_vec3	b;
	double 	alpha;
	double 	beta;

    vec3_sub(&pq, p, self->coor);
    vec3_cross(&a, &pq, self->v);
    vec3_cross(&b, self->u, &pq);
    alpha = vec3_dot(&q->w, &a);
    beta = vec3_dot(&q->w, &b);

    // Verifica si el punto está dentro del cuadrilátero
    if (alpha < 0 || alpha > 1 || beta < 0 || beta > 1) {
        return false;  // El punto de intersección está fuera del cuadrilátero
    }
	return true;
}

//the ray orig + dir * t, hits de plane when a ray point dotted wiht plane 
// normal equals D, being plane formula Ax + By + Cz = D
// n dot (orig + dir * t) = d, solved for t gives the impact point.
// denom if zero means the ray is parallet to plane
// we consider that is pararalel if < 0.00000001
// d comes form novec (normal) dotted with coor(point in plane)
// t, the distance to the impact point has to be inside de interval ran
// p is the impact point at t distance
bool	hit_plane(t_eleme *self, t_ray *ray, t_interval *ran, t_hitrecord *rec)
{
	double	denom;
	double	d;
	double	t;
	t_point	*p;


	denom = vec3_dot(self->novec, ray->dir);
	if (fabs(denom) < 1e-8)
        return false;
	d = vec3_dot(self->novec, self->coor);
    t = (d - vec3_dot(self->novec, ray->orig)) / denom;
    if (!interval_contains(ran, t))
        return false;
    p = ray_at(ray, t);
	if (!lies_within_planar_shape(self, p))
		return false;
    rec->t = t;
    rec->p = P;
    //rec->mat_ptr = ((Quad*)self)->mat;
    rec->hit_obj = self;
	hitrecord_face_normal(rec, ray, self->novec);
	point_free(p);
    return true;
}
t_eleme	*eleme_new_pla(t_vec3 *coor, t_vec3 *novec, t_color *rgb255)
{
	t_eleme	*self;

	self = eleme_new();
	if (!self)
		return (NULL);
	vec3_u_v_from_n(novec, self->u, self->v);
	eleme_set_ident(self, PLANE);
	eleme_set_coord(self, coor);
	eleme_set_novec(self, novec);
	eleme_set_color(self, rgb255);
	eleme_set_diame(self, 0.0);
	eleme_set_heigh(self, 0.0);
	eleme_set_hit(self, hit_plane);
	return (self);
}
