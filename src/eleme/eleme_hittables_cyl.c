/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_hittables_cyl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:40:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/05 20:42:12 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "eleme.h"

static double	calc_discriminant(t_eleme *self, t_ray *ray,
		double *half_b, double	*a)
{
	double	c;
	t_vec3	oc;
	t_vec3	d_proj;
	t_vec3	oc_proj;

	vec3_sub(&oc, ray->orig, self->coor);
	vec3_scale(&d_proj, self->novec, vec3_dot(self->novec, ray->dir));
	vec3_sub(&d_proj, ray->dir, &d_proj);
	vec3_scale(&oc_proj, self->novec, vec3_dot(self->novec, &oc));
	vec3_sub(&oc_proj, &oc, &oc_proj);
	*a = vec3_length_squared(&d_proj);
	c = vec3_length_squared(&oc_proj) - ((self->d / 2) * (self->d / 2));
	*half_b = vec3_dot(&d_proj, &oc_proj);
	return (*half_b * *half_b - *a * c);
}

static void	set_hitrecord_tap(t_hitrecord *hr, double t, t_point *p,
	t_eleme *s, t_ray *ra)
{
	hitrecord_set_t(hr, t);
	hitrecord_set_point(hr, p);
	hitrecord_set_hit_obj(hr, s);
	hitrecord_set_normal(hr, s->novec);
	hitrecord_set_front_face(hr,
		(vec3_dot(ray_get_dir(ra), hitrecord_get_normal(hr)) < 0));
	//rec->mat_ptr = cil->mat;
	if (!hitrecord_get_front_face(hr))
		hitrecord_reverse_normal(hr);
}

static int	calc_intersect_tap_bottom(t_eleme *self, t_ray *ray,
	double denom, t_hitrecord *rec)
{
	t_vec3	half_height;
	t_vec3	center;
	t_vec3	from_cen;
	double	t;
	t_point	*p;

	vec3_scale(&half_height, self->novec, self->d / 2);
	vec3_add(&center, self->coor, &half_height);
	t = (vec3_dot(self->novec, &center) - vec3_dot(self->novec, ray->orig));
	t = t / denom;
	if (interval_contains(ray, t))
	{
		p = ray_at(ray, t);
		point_free(p);
		vec3_sub(&from_cen, &p, &center);
		if (vec3_length_squared(&from_cen) <= ((self->d / 2) * (self->d / 2)))
		{
			set_hitrecord_tap(rec, t, p, self, ray);
			return (1);
		}
		return (0);
	}
	return (0);
}

static int	calc_intersect_tap_top(t_eleme *self, t_ray *ray,
		double denom, t_hitrecord *rec)
{
	t_vec3		half_height;
	t_vec3		center;
	t_vec3		from_cen;
	double		t;
	t_point		*p;

	vec3_scale(&half_height, self->novec, self->d / 2);
	vec3_sub(&center, self->coor, &half_height);
	t = (vec3_dot(self->novec, &center) - vec3_dot(self->novec, ray->orig));
	t = t / denom;
	if (interval_contains(ray, t))
	{
		p = ray_at(ray, t);
		vec3_sub(&from_cen, &p, &center);
		if (vec3_length_squared(&from_cen) <= ((self->d / 2) * (self->d / 2)))
		{
			set_hitrecord_tap(rec, t, p, self, ray);
			point_free(p);
			return (1);
		}
		point_free(p);
		return (0);
	}
	return (0);
}
static void	set_hitrecord_body(t_hitrecord *hr, double t, t_point *p,
	t_eleme *s, t_ray *ra)
{
}
static int	calc_intersect_body(double disc, double half_b, double a,
	t_eleme *self, t_ray *ray)
{
	double	sqrt_disc;
	double	root;
	t_point	*hit_point;
	t_vec3	center_to_hit;
	double	height_proj;

	sqrt_disc = sqrt(disc);
	root = (-half_b - sqrt_disc) / a;
	if (!interval_contains(ray, root))
	{
		root = (-half_b + sqrt_disc) / a;
		if (!interval_contains(ray, root))
			return (false);
	}
	hit_point = ray_at(ray, root);
	point_free(hit_point);
	vec3_sub(&center_to_hit, &hit_point, self->coor);
	height_proj = vec3_dot(&center_to_hit, self->novec);
	if (((-self->h / 2) <= height_proj) && (height_proj <= (self->h / 2)))
	{
		rec->t = root;
		rec->p = hit_point;
		rec->mat_ptr = cil->mat;
		rec->hit_obj = (void*)cil;
		vec3_scale(&scale_proj, &cil->axis, height_proj);
		vec3_sub(&outward_normal, &center_to_hit, &scale_proj);
		vec3_unit_vector(&rec->normal, &outward_normal);
		rec->front_face = vec3_dot(&r->dir, &rec->normal) < 0;
		if (!rec->front_face)
			vec3_negate(&rec->normal, &rec->normal);
		return (true);
	}
}

bool	hit_cyl(t_eleme *self, t_ray *ray, t_interval *ran, t_hitrecord *rec)
{
	double	a;
	double	half_b;
	double	discriminant;
	double	denom;

	discriminant = calc_discriminant(self, ray, &half_b, &a);
	if (discriminant >= 0)
	{
		if (calc_intersect_body(discriminant, half_b, a, ray))
			return (true);
	}
	denom = vec3_dot(self->novec, ray->dir);
	if (fabs(denom) > 1e-8)
	{
		if (calc_intersect_tap_bottom(self, ray, denom, rec))
			return (true);
		if (calc_intersect_tap_top(self, ray, denom, rec))
			return (true);
	}
	return (false);
}
