/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 07:43:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/25 20:05:35 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

double	point_get_x(t_point *self)
{
	return (vec3_get_x(self));
}

double	point_get_y(t_point *self)
{
	return (vec3_get_y(self));
}

double	point_get_z(t_point *self)
{
	return (vec3_get_z(self));
}
