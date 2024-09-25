/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:09:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/25 20:03:53 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

void	point_set_x(t_point *self, double the_x)
{
	vec3_set_x(self, the_x);
}

void	point_set_y(t_point *self, double the_y)
{
	vec3_set_y(self, the_y);
}

void	point_set_z(t_point *self, double the_z)
{
	vec3_set_z(self, the_z);
}
