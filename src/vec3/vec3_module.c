/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   vec3_module.c                                      :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: luicasad <luicasad@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/07 12:47:07 by luicasad		  #+#	#+#			 */
/*   Updated: 2024/11/13 17:58:47 by luicasad         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "vec3.h"
#include "stdlib.h"
#include "libft.h"

double	vec3_length_squared(const t_vec3 *v)
{
	return (v->e[0] * v->e[0] + v->e[1] * v->e[1] + v->e[2] * v->e[2]);
}

double	vec3_length(const t_vec3 *v)
{
	return (sqrt(vec3_length_squared(v)));
}

void	vec3_unit_vector(t_vec3 *result, const t_vec3 *v)
{
	vec3_div(result, v, vec3_length(v));
}

// randomly generates a non parallelel vector to normal
// with product co
void	vec3_u_v_from_n(t_vec3 *n, t_vec3 *u, t_vec3 *v)
{
	if (!vec3_iszero(n))
	{
		vec3_unit_vector(n, n);
		vec3_random(u, -0.5, 0.5);
		while (vec3_dot(n, u) == 0)
			vec3_random(u, -0.5, 0.5);
		vec3_unit_vector(u, u);
		vec3_cross(v, n, u);
	}
}
