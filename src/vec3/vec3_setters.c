/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_setters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:37:41 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/14 09:19:04 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

void	vec3_set_x(t_vec3 *v, double value)
{
	v->e[0] = value;
}

void	vec3_set_y(t_vec3 *v, double value)
{
	v->e[1] = value;
}

void	vec3_set_z(t_vec3 *v, double value)
{
	v->e[2] = value;
}

void	vec3_set(t_vec3 *v, int i, double value)
{
	v->e[i] = value;
}
