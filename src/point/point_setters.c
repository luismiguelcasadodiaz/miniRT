/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:09:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/13 07:43:20 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

void	point_set_x(t_point *self, int the_x)
{
	self->x = the_x;
}

void	point_set_y(t_point *self, int the_y)
{
	self->y = the_y;
}

void	point_set_z(t_point *self, int the_z)
{
	self->z = the_z;
}
