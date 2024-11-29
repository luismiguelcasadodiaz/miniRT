/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_hittables_cyl_one.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:40:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/12 22:39:53 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "eleme.h"

static void	set_hitrecord_tap(t_hit_args *data, double t, t_point *p)
{
	hitrecord_set_t(data->rec, t);
	hitrecord_set_point(data->rec, p);
	hitrecord_set_hit_obj(data->rec, data->self);
	hitrecord_set_normal(data->rec, data->self->novec);
	hitrecord_set_front_face(data->rec,
		(vec3_dot(ray_get_dir(data->ray),
				hitrecord_get_normal(data->rec)) < 0));
	if (!hitrecord_get_front_face(data->rec))
		hitrecord_reverse_normal(data->rec);
}
	//rec->mat_ptr = cil->mat;

static	double	get_t(t_hit_args *data, double denom, t_vec3fp vec3_func,
		t_vec3 *center)
{
	t_vec3		half_height;
	double		t;

	vec3_scale(&half_height, data->self->novec, data->self->h / 2.0);
	vec3_func(center, data->self->coor, &half_height);
	t = (vec3_dot(data->self->novec, center)
			- vec3_dot(data->self->novec, data->ray->orig));
	t = t / denom;
	return (t);
}

static int	calc_tap(t_hit_args *data, double denom, t_vec3fp vec3_func)
{
	t_vec3		center;
	t_vec3		from_cen;
	double		t;
	t_point		*p;

	t = get_t(data, denom, vec3_func, &center);
	if (int_contains(data->ran, t))
	{
		p = ray_at(data->ray, t);
		vec3_sub(&from_cen, p, &center);
		if (vec3_length_squared(&from_cen)
			<= ((data->self->d / 2.0) * (data->self->d / 2.0)))
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

bool	hit_cyl(t_hit_args *data)
{
	double	a;
	double	half_b;
	double	discriminant;
	double	denom;

	discriminant = calc_discriminant(data->self, data->ray, &half_b, &a);
	if (discriminant >= 0)
	{
		if (calc_body(data, discriminant, half_b, a))
			return (true);
	}
	denom = vec3_dot(data->self->novec, data->ray->dir);
	if (fabs(denom) > 1e-8)
	{
		if (calc_tap(data, denom, vec3_add))
			return (true);
		if (calc_tap(data, denom, vec3_sub))
			return (true);
	}
	return (false);
}
