/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:33:42 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/16 16:11:54 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>

typedef struct s_vec3
{
	double	e[3];
}	t_vec3;

// init functions (vec3_init.c)
t_vec3	*vec3_new(void);
void	vec3_free(t_vec3 *self);
void	vec3_init(t_vec3 *v);
void	vec3_init_values(t_vec3 *v, double e0, double e1, double e2);
void	vec3_copy_values(t_vec3 *dest, t_vec3 *orig);
void	vec3_print(const t_vec3 *v);
// getters (vec3_getters.c)
double	vec3_get_x(const t_vec3 *v);
double	vec3_get_y(const t_vec3 *v);
double	vec3_get_z(const t_vec3 *v);
double	vec3_get_i(const t_vec3 *v, int i);
// setters (vec3_setters.c)
void	vec3_set_x(t_vec3 *v, double value);
void	vec3_set_y(t_vec3 *v, double value);
void	vec3_set_z(t_vec3 *v, double value);
void	vec3_set_i(t_vec3 *v, double value, int i);
// Addition functions (vec3_addition.c)
void	vec3_add(t_vec3 *result, const t_vec3 *u, const t_vec3 *v);
void	vec3_sub(t_vec3 *result, const t_vec3 *u, const t_vec3 *v);
void	vec3_negate(t_vec3 *result, const t_vec3 *v);
// Product functions (vec3_product.c)
void	vec3_mul(t_vec3 *result, const t_vec3 *u, double t);
void	vec3_div(t_vec3 *result, const t_vec3 *v, double t);
void	vec3_scale(t_vec3 *result, const t_vec3 *v, double t);
double	vec3_dot(const t_vec3 *u, const t_vec3 *v);
void	vec3_cross(t_vec3 *result, const t_vec3 *u, const t_vec3 *v);
// module functions (vec3_module.c)
double	vec3_length_squared(const t_vec3 *v);
double	vec3_length(const t_vec3 *v);
void	vec3_unit_vector(t_vec3 *result, const t_vec3 *v);
#endif
