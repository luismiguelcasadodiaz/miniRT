/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 07:43:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/13 07:45:18 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

int	point_get_x(t_point *self)
{
	return (self->x);
}

int	point_get_y(t_point *self)
{
	return (self->y);
}

int	point_get_z(t_point *self)
{
	return (self->z);
}
