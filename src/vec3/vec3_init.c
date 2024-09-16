/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   vec3_init.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: luicasad <luicasad@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/07 12:47:07 by luicasad		  #+#	#+#			 */
/*   Updated: 2024/09/16 16:02:52 by luicasad         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "vec3.h"
#include <stdio.h>
#include <stdlib.h>

t_vec3	*vec3_new(void)
{
	t_vec3	*self;

	self = (t_vec3 *)malloc(sizeof(t_vec3));
	if (!self)
		return (NULL);
	vec3_init(self);
	return (self);
}

void	vec3_free(t_vec3 *self)
{
	free(self);
}

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

void	vec3_copy_values(t_vec3 *dest, t_vec3 *orig)
{
	dest->e[0] = orig->e[0];
	dest->e[1] = orig->e[1];
	dest->e[2] = orig->e[2];
}
