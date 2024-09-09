/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: luicasad <luicasad@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/07 12:47:07 by luicasad		  #+#	#+#			 */
/*   Updated: 2024/09/07 21:47:04 by luicasad         ###   ########.fr       */
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
void	vec3_init_values(t_vec3 *v, double e0, double e1, double e2)
{
	v->x = e0;
	v->y = e1;
	v->z = e2;
}

double	vec3_x(const t_vec3 *v)
{
	return (v->x);
}

double	vec3_y(const t_vec3 *v)
{
	return (v->y);
}

double	vec3_z(const t_vec3 *v)
{
	return (v->z);
}

void	vec3_negate(t_vec3 *result, const t_vec3 *v)
{
	vec3_init_values(result, -v->x, -v->y, -v->z);
}

double	vec3_get(const t_vec3 *v, int i)
{
	if (i == 0)
		return (v->x);
	if (i == 1)
		return (v->y);
	if (i == 2)
		return (v->z);
	return (0);
}

void	vec3_set(t_vec3 *v, int i, double value)
{
	if (i == 0)
		v->x = value;
	if (i == 1)
		v->y = value;
	if (i == 2)
		v->z = value;
}

void	vec3_add(t_vec3 *result, const t_vec3 *u, const t_vec3 *v)
{
	result->x = u->x + v->x;
	result->y = u->y + v->y;
	result->z = u->z + v->z;
}

void	vec3_sub(t_vec3 *result, const t_vec3 *u, const t_vec3 *v)
{
	result->x = u->x - v->x;
	result->y = u->y - v->y;
	result->z = u->z - v->z;
}

void	vec3_mul(t_vec3 *result, const t_vec3 *u, const t_vec3 *v)
{
	result->x = u->x * v->x;
	result->y = u->y * v->y;
	result->z = u->z * v->z;
}

void	vec3_scale(t_vec3 *result, const t_vec3 *v, double t)
{
	result->x = t * v->x;
	result->y = t * v->y;
	result->z = t * v->z;
}

void	vec3_div(t_vec3 *result, const t_vec3 *v, double t)
{
	vec3_scale(result, v, 1 / t);
}

double	vec3_length_squared(const t_vec3 *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}

double	vec3_length(const t_vec3 *v)
{
	return (sqrt(vec3_length_squared(v)));
}

double	vec3_dot(const t_vec3 *u, const t_vec3 *v)
{
	return (u->x * v->x + u->y * v->y + u->z * v->z);
}

void	vec3_cross(t_vec3 *result, const t_vec3 *u, const t_vec3 *v)
{
	vec3_init_values(result,
		u->y * v->z - u->z * v->y,
		u->z * v->x - u->x * v->z,
		u->x * v->y - u->y * v->x);
}

void	vec3_unit_vector(t_vec3 *result, const t_vec3 *v)
{
	vec3_div(result, v, vec3_length(v));
}

void	vec3_print(const t_vec3 *v)
{
	printf("%f %f %f\n", v->x, v->y, v->z);
}
