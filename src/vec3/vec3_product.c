/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_product.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:28:35 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/13 12:20:48 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec3.h"

void	vec3_mul_lmcd(t_vec3 *result, const t_vec3 *u, double t)
{
	result->e[0] = u->e[0] * t;
	result->e[1] = u->e[1] * t;
	result->e[2] = u->e[2] * t;
}

void	vec3_mul(t_vec3 *result, const t_vec3 *u, const t_vec3 *v)
{
	result->e[0] = u->e[0] * v->e[0];
	result->e[1] = u->e[1] * v->e[1];
	result->e[2] = u->e[2] * v->e[2];
}

void	vec3_div(t_vec3 *result, const t_vec3 *v, double t)
{
	vec3_scale(result, v, 1.0 / t);
}

void	vec3_scale(t_vec3 *result, const t_vec3 *v, double t)
{
	result->e[0] = t * v->e[0];
	result->e[1] = t * v->e[1];
	result->e[2] = t * v->e[2];
}

double	vec3_dot(const t_vec3 *u, const t_vec3 *v)
{
	return (u->e[0] * v->e[0] + u->e[1] * v->e[1] + u->e[2] * v->e[2]);
}

void	vec3_cross(t_vec3 *result, const t_vec3 *u, const t_vec3 *v)
{
	vec3_init_values(result,
		u->e[1] * v->e[2] - u->e[2] * v->e[1],
		u->e[2] * v->e[0] - u->e[0] * v->e[2],
		u->e[0] * v->e[1] - u->e[1] * v->e[0]);
}
