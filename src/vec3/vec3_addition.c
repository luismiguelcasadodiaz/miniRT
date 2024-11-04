/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:31:45 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/12 12:36:42 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec3.h"

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

void	vec3_negate(t_vec3 *result, const t_vec3 *u)
{
	result->e[0] -= u->e[0];
	result->e[1] -= u->e[1];
	result->e[2] -= u->e[2];
}

int 	vec3_iszero(t_vec3 *v)
{
	if ((v->e[0] == 0) && (v->e[1] == 0) && (v->e[2] == 0))
		return (1);
	return(0);
}


int 	vec3_in_range(t_vec3 *self, float min, float max)
{
	int	result;

	result  = ((min <= self->e[0]) && (self->e[0] <= max));
	result  = result  && ((min <= self->e[1]) && (self->e[1] <= max));
	result  = result  && ((min <= self->e[2]) && (self->e[2] <= max));
	return (result);
}