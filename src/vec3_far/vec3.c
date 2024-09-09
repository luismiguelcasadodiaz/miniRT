/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: luicasad <luicasad@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/07 12:47:07 by luicasad		  #+#	#+#			 */
/*   Updated: 2024/09/07 21:33:39 by luicasad         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "vec3.h"

// Constructor por defecto
void	vec3_init(t_vec3 *v)
{
	v->e[0] = 0;
	v->e[1] = 0;
	v->e[2] = 0;
}

// Constructor con parámetros
void	vec3_init_values(t_vec3 *v, float e0, float e1, float e2)
{
	v->e[0] = e0;
	v->e[1] = e1;
	v->e[2] = e2;
}

float	vec3_x(const t_vec3 *v)
{
	return (v->e[0]);
}

float	vec3_y(const t_vec3 *v)
{
	return (v->e[1]);
}

float	vec3_z(const t_vec3 *v)
{
	return (v->e[2]);
}

void	vec3_negate(t_vec3 *result, const t_vec3 *v)
{
	vec3_init_values(result, -v->e[0], -v->e[1], -v->e[2]);
}

float	vec3_get(const t_vec3 *v, int i)
{
	return (v->e[i]);
}

void	vec3_set(t_vec3 *v, int i, float value)
{
	v->e[i] = value;
}

void	vec3_add(t_vec3 *result, const t_vec3 *u, const t_vec3 *v)
{
	result->e[0] = u->e[0] + v->e[0];
	result->e[1] = u->e[1] + v->e[1];
	result->e[2] = u->e[2] + v->e[2];
}

void	vec3_sub(t_vec3 *result, const t_vec3 *u, const t_vec3 *v)
{
	result->e[0] = u->e[0] - v->e[0];
	result->e[1] = u->e[1] - v->e[1];
	result->e[2] = u->e[2] - v->e[2];
}

void	vec3_mul(t_vec3 *result, const t_vec3 *u, const t_vec3 *v)
{
	result->e[0] = u->e[0] * v->e[0];
	result->e[1] = u->e[1] * v->e[1];
	result->e[2] = u->e[2] * v->e[2];
}

void	vec3_scale(t_vec3 *result, const t_vec3 *v, float t)
{
	result->e[0] = t * v->e[0];
	result->e[1] = t * v->e[1];
	result->e[2] = t * v->e[2];
}

void	vec3_div(t_vec3 *result, const t_vec3 *v, float t)
{
	vec3_scale(result, v, 1 / t);
}

float	vec3_length_squared(const t_vec3 *v)
{
	return (v->e[0] * v->e[0] + v->e[1] * v->e[1] + v->e[2] * v->e[2]);
}

float	vec3_length(const t_vec3 *v)
{
	return (sqrt(vec3_length_squared(v)));
}

float	vec3_dot(const t_vec3 *u, const t_vec3 *v)
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

void	vec3_unit_vector(t_vec3 *result, const t_vec3 *v)
{
	vec3_div(result, v, vec3_length(v));
}

void	vec3_print(const t_vec3 *v)
{
	printf("%f %f %f\n", v->e[0], v->e[1], v->e[2]);
}
