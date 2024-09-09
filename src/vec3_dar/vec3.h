/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:33:42 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/07 12:41:26 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>
# include <stdio.h>

typedef struct s_vec3
{
	double	e[3];
}	t_vec3;

//Declaracion de funciones
void	vec3_init(t_vec3 *v);
void	vec3_init_values(t_vec3 *v, double e0, double e1, double e2);
double	vec3_x(const t_vec3 *v);
double	vec3_y(const t_vec3 *v);
double	vec3_z(const t_vec3 *v);
void	vec3_negate(t_vec3 *result, const t_vec3 *v);
double	vec3_get(const t_vec3 *v, int i);
void	vec3_set(t_vec3 *v, int i, double value);
void	vec3_add(t_vec3 *result, const t_vec3 *u, const t_vec3 *v);
void	vec3_sub(t_vec3 *result, const t_vec3 *u, const t_vec3 *v);
void	vec3_mul(t_vec3 *result, const t_vec3 *u, const t_vec3 *v);
void	vec3_scale(t_vec3 *result, const t_vec3 *v, double t);
void	vec3_div(t_vec3 *result, const t_vec3 *v, double t);
double	vec3_length_squared(const t_vec3 *v);
double	vec3_length(const t_vec3 *v);
double	vec3_dot(const t_vec3 *u, const t_vec3 *v);
void	vec3_cross(t_vec3 *result, const t_vec3 *u, const t_vec3 *v);
void	vec3_unit_vector(t_vec3 *result, const t_vec3 *v);
void	vec3_print(const t_vec3 *v);
#endif
