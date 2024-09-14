/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   module.c                                           :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: luicasad <luicasad@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/07 12:47:07 by luicasad		  #+#	#+#			 */
/*   Updated: 2024/09/12 12:27:34 by luicasad         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "vec3.h"

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
