/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: luicasad <luicasad@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/07 12:47:07 by luicasad		  #+#	#+#			 */
/*   Updated: 2024/09/12 12:41:46 by luicasad         ###   ########.fr       */
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
void	vec3_init_values(t_vec3 *v, double e0, double e1, double e2)
{
	v->e[0] = e0;
	v->e[1] = e1;
	v->e[2] = e2;
}

void	vec3_print(const t_vec3 *v)
{
	printf("[x=%f y=%f z=%f]\n", v->e[0], v->e[1], v->e[2]);
}
