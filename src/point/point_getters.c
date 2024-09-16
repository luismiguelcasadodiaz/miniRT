/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 07:43:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/16 12:11:57 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

double	point_get_x(t_point *self)
{
	return (self->x);
}

double	point_get_y(t_point *self)
{
	return (self->y);
}

double	point_get_z(t_point *self)
{
	return (self->z);
}
