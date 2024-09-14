/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:37:41 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/14 09:15:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	vec3_get_x(const t_vec3 *v)
{
	return (v->e[0]);
}

double	vec3_get_y(const t_vec3 *v)
{
	return (v->e[1]);
}

double	vec3_get_z(const t_vec3 *v)
{
	return (v->e[2]);
}

double	vec3_get_i(const t_vec3 *v, int i)
{
	return (v->e[i]);
}
