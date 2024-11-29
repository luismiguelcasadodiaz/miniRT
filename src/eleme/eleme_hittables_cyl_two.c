/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_hittables_cyl_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:40:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/12 22:38:40 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "eleme.h"

static void	set_hitrecord_body_one(t_hit_args *data, double root,
		t_point *hit_point)
{
	hitrecord_set_t(data->rec, root);
	hitrecord_set_point(data->rec, hit_point);
	hitrecord_set_hit_obj(data->rec, data->self);
}

static void	set_hitrecord_body_two(t_hit_args *data, double height_proj,
		t_vec3 *center_to_hit)
{
	t_vec3	scale_proj;
	t_vec3	outward_normal;

	vec3_scale(&scale_proj, data->self->novec, height_proj);
	vec3_sub(&outward_normal, center_to_hit, &scale_proj);
	hitrecord_set_normal(data->rec, &outward_normal);
	hitrecord_unit_normal(data->rec);
	hitrecord_set_front_face(data->rec,
		(vec3_dot(ray_get_dir(data->ray),
				hitrecord_get_normal(data->rec)) < 0));
	if (!hitrecord_get_front_face(data->rec))
		hitrecord_reverse_normal(data->rec);
}
	//rec->mat_ptr = cil->mat;

//static int get_root(t_hit_args *data, double disc, double half_b, double a)
//aux->[0]  holds disc
//aux->e[1] holds half_b
//aux->e[2] holds a
static int	get_root(t_hit_args *data, t_vec3 aux, double *root)
{
	double	sqrt_disc;

	sqrt_disc = sqrt(aux.e[0]);
	*root = (-aux.e[1] - sqrt_disc) / aux.e[2];
	if (!int_contains(data->ran, *root))
	{
		*root = (-aux.e[1] + sqrt_disc) / aux.e[2];
		if (!int_contains(data->ran, *root))
			return (false);
	}
	return (true);
}

int	calc_body(t_hit_args *data, double disc, double half_b, double a)
{
	double	root;
	t_point	*hit_point;
	t_vec3	center_to_hit;
	double	height_proj;

	vec3_init_values(&center_to_hit, disc, half_b, a);
	if (!get_root(data, center_to_hit, &root))
		return (false);
	hit_point = ray_at(data->ray, root);
	vec3_sub(&center_to_hit, hit_point, data->self->coor);
	height_proj = vec3_dot(&center_to_hit, data->self->novec);
	if (((-data->self->h / 2.0)
			<= height_proj) && (height_proj <= (data->self->h / 2.0)))
	{
		set_hitrecord_body_one(data, root, hit_point);
		set_hitrecord_body_two(data, height_proj, &center_to_hit);
		point_free(hit_point);
		return (true);
	}
	point_free(hit_point);
	return (false);
}
