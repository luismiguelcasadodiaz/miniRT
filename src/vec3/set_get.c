/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:37:41 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/12 12:38:55 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	vec3_x(const t_vec3 *v)
{
	return (v->e[0]);
}

double	vec3_y(const t_vec3 *v)
{
	return (v->e[1]);
}

double	vec3_z(const t_vec3 *v)
{
	return (v->e[2]);
}

double	vec3_get(const t_vec3 *v, int i)
{
	return (v->e[i]);
}

void	vec3_set(t_vec3 *v, int i, double value)
{
	v->e[i] = value;
}
