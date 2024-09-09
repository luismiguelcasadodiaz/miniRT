/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:33:42 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/08 08:47:15 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>
# include <stdio.h>

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

//Declaracion de funciones
void	vec3_init(t_vec3 *v);
void	vec3_init_values(t_vec3 *v, float e0, float e1, float e2);
float	vec3_x(const t_vec3 *v);
float	vec3_y(const t_vec3 *v);
float	vec3_z(const t_vec3 *v);
void	vec3_negate(t_vec3 *result, const t_vec3 *v);
float	vec3_get(const t_vec3 *v, int i);
void	vec3_set(t_vec3 *v, int i, float value);
void	vec3_add(t_vec3 *result, const t_vec3 *u, const t_vec3 *v);
void	vec3_sub(t_vec3 *result, const t_vec3 *u, const t_vec3 *v);
void	vec3_mul(t_vec3 *result, const t_vec3 *u, const t_vec3 *v);
void	vec3_scale(t_vec3 *result, const t_vec3 *v, float t);
void	vec3_div(t_vec3 *result, const t_vec3 *v, float t);
float	vec3_length_squared(const t_vec3 *v);
float	vec3_length(const t_vec3 *v);
float	vec3_dot(const t_vec3 *u, const t_vec3 *v);
void	vec3_cross(t_vec3 *result, const t_vec3 *u, const t_vec3 *v);
void	vec3_unit_vector(t_vec3 *result, const t_vec3 *v);
void	vec3_print(const t_vec3 *v);
#endif
