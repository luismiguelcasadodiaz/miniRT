/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: luicasad <luicasad@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/07 12:47:07 by luicasad		  #+#	#+#			 */
/*   Updated: 2024/09/08 10:22:51 by luicasad         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "vec3.h"

// Constructor por defecto
void	vec3_init(t_vec3 *v)
{
	v->x = 0;
	v->y = 0;
	v->z = 0;
}

// Constructor con parámetros
void	vec3_init_values(t_vec3 *v, float e0, float e1, float e2)
{
	v->x = e0;
	v->y = e1;
	v->z = e2;
}

float	vec3_x(const t_vec3 *v)
{
	return (v->x);
}

float	vec3_y(const t_vec3 *v)
{
	return (v->y);
}

float	vec3_z(const t_vec3 *v)
{
	return (v->z);
}

void	vec3_negate(t_vec3 *result, const t_vec3 *v)
{
	vec3_init_values(result, -v->x, -v->y, -v->z);
}

float	vec3_get(const t_vec3 *v, int i)
{
	if (i == 0)
		return (v->x);
	if (i == 1)
		return (v->y);
	if (i == 2)
		return (v->z);
	return (0);
}

void	vec3_set(t_vec3 *v, int i, float value)
{
	if (i == 0)
		v->x = value;
	if (i == 1)
		v->y = value;
	if (i == 2)
		v->z = value;
}

t_vec3	vec3_add(const t_vec3 u, const t_vec3 v)
{
	t_vec3	result;

	result.x = u.x + v.x;
	result.y = u.y + v.y;
	result.z = u.z + v.z;
	return (result);
}

t_vec3	vec3_sub(const t_vec3 u, const t_vec3 v)
{
	t_vec3	result;

	result.x = u.x - v.x;
	result.y = u.y - v.y;
	result.z = u.z - v.z;
	return (result);
}

t_vec3	vec3_mul(const t_vec3 u, const t_vec3 v)
{
	t_vec3	result;

	result.x = u.x * v.x;
	result.y = u.y * v.y;
	result.z = u.z * v.z;
	return (result);
}

void	vec3_scale(t_vec3 *result, const t_vec3 *v, float t)
{
	result->x = t * v->x;
	result->y = t * v->y;
	result->z = t * v->z;
}

void	vec3_div(t_vec3 *result, const t_vec3 *v, float t)
{
	vec3_scale(result, v, 1 / t);
}

float	vec3_length_squared(const t_vec3 *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}

float	vec3_length(const t_vec3 *v)
{
	return (sqrt(vec3_length_squared(v)));
}

float	vec3_dot(const t_vec3 u, const t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec3	vec3_cross(const t_vec3 u, const t_vec3 v)
{
	t_vec3	r;

		r.x = u.y * v.z - u.z * v.y;
		r.y = u.z * v.x - u.x * v.z;
		r.z = u.x * v.y - u.y * v.x;
	return (r);
}

void	vec3_unit_vector(t_vec3 *result, const t_vec3 *v)
{
	vec3_div(result, v, vec3_length(v));
}

void	vec3_print(const t_vec3 *v)
{
	printf("%f %f %f\n", v->x, v->y, v->z);
}
