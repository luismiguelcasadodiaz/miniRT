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

static void	set_hitrecord_tap(t_hit_args *data, double t, t_point *p)
{
	hitrecord_set_t(data->rec, t);
	hitrecord_set_point(data->rec, p);
	hitrecord_set_hit_obj(data->rec, data->self);
	hitrecord_set_normal(data->rec, data->self->novec);
	hitrecord_set_front_face(data->rec,
		(vec3_dot(ray_get_dir(data->ray), hitrecord_get_normal(data->rec)) < 0));
	//rec->mat_ptr = cil->mat;
	if (!hitrecord_get_front_face(data->rec))
		hitrecord_reverse_normal(data->rec);
}
/*
static int	calc_intersect_tap_bottom(t_hit_args *data, double denom )
{
	t_vec3	half_height;
	t_vec3	center;
	t_vec3	from_cen;
	double	t;
	t_point	*p;

	vec3_scale(&half_height, self->novec, self->d / 2.0);
	vec3_add(&center, self->coor, &half_height);
	t = (vec3_dot(self->novec, &center) - vec3_dot(self->novec, ray->orig));
	t = t / denom;
	if (interval_contains(ran, t))
	{
		p = ray_at(ray, t);
		
		vec3_sub(&from_cen, p, &center);
		if (vec3_length_squared(&from_cen) <= ((self->d / 2.0) * (self->d / 2.0)))
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
*/


static int	calc_intersect_tap(t_hit_args *data, double denom, t_vec3fp vec3_func)
{
	t_vec3		half_height;
	t_vec3		center;
	t_vec3		from_cen;
	double		t;
	t_point		*p;

	vec3_scale(&half_height, data->self->novec, data->self->d / 2.0);
	vec3_func(&center, data->self->coor, &half_height);
	t = (vec3_dot(data->self->novec, &center) - vec3_dot(data->self->novec, data->ray->orig));
	t = t / denom;
	if (interval_contains(data->ran, t))
	{
		p = ray_at(data->ray, t);
		vec3_sub(&from_cen, p, &center);
		if (vec3_length_squared(&from_cen) <= ((data->self->d / 2.0) * (data->self->d / 2.0)))
		{
			set_hitrecord_tap(data, t, p);
			point_free(p);
			return (1);
		}
		point_free(p);
		return (0);
	}
	return (0);
}



/*

static int	calc_intersect_tap_top(t_hit_args *data, double denom)
{
	t_vec3		half_height;
	t_vec3		center;
	t_vec3		from_cen;
	double		t;
	t_point		*p;

	vec3_scale(&half_height, self->novec, self->d / 2.0);
	vec3_sub(&center, self->coor, &half_height);
	t = (vec3_dot(self->novec, &center) - vec3_dot(self->novec, ray->orig));
	t = t / denom;
	if (interval_contains(ran, t))
	{
		p = ray_at(ray, t);
		vec3_sub(&from_cen, p, &center);
		if (vec3_length_squared(&from_cen) <= ((self->d / 2.0) * (self->d / 2.0)))
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
*/

static void	set_hitrecord_body(t_hit_args *data, double root, double	height_proj, t_vec3	*center_to_hit, t_point *hit_point)
	
{
	t_vec3	scale_proj;
	t_vec3	outward_normal;

	hitrecord_set_t(data->rec, root);
	hitrecord_set_point(data->rec, hit_point);
	hitrecord_set_hit_obj(data->rec, data->self);
	vec3_scale(&scale_proj, data->self->novec, height_proj);
	vec3_sub(&outward_normal, center_to_hit, &scale_proj);
	hitrecord_set_normal(data->rec, &outward_normal);
	hitrecord_unit_normal(data->rec);
	hitrecord_set_front_face(data->rec,
		(vec3_dot(ray_get_dir(data->ray), hitrecord_get_normal(data->rec)) < 0));
	if (!hitrecord_get_front_face(data->rec))
	hitrecord_reverse_normal(data->rec);
	//rec->mat_ptr = cil->mat;
}

static int	calc_intersect_body(t_hit_args *data, double disc, double half_b, double a)
{
	double	sqrt_disc;
	double	root;
	t_point	*hit_point;
	t_vec3	center_to_hit;
	double	height_proj;

	sqrt_disc = sqrt(disc);
	root = (-half_b - sqrt_disc) / a;
	if (!interval_contains(data->ran, root))
	{
		root = (-half_b + sqrt_disc) / a;
		if (!interval_contains(data->ran, root))
			return (false);
	}
	hit_point = ray_at(data->ray, root);
	
	vec3_sub(&center_to_hit, hit_point, data->self->coor);

	height_proj = vec3_dot(&center_to_hit, data->self->novec);
	if (((-data->self->h / 2.0) <= height_proj) && (height_proj <= (data->self->h / 2.0)))
	{
		set_hitrecord_body(data, root, height_proj, &center_to_hit, hit_point);
		point_free(hit_point);
		return (true);
	}
	point_free(hit_point);
	return (false);
}

bool	hit_cyl(t_hit_args *data)
{
	double	a;
	double	half_b;
	double	discriminant;
	double	denom;

	discriminant = calc_discriminant(data->self, data->ray, &half_b, &a);
	if (discriminant >= 0)
	{
		if (calc_intersect_body(data, discriminant, half_b, a))
			return (true);
	}
	denom = vec3_dot(data->self->novec, data->ray->dir);
	if (fabs(denom) > 1e-8)
	{
		if (calc_intersect_tap(data, denom, vec3_add))
			return (true);
		if (calc_intersect_tap(data, denom, vec3_sub))
			return (true);
	}
	return (false);
}
