/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:09:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/25 20:01:45 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include <stdlib.h>

t_point	*point_new(void)
{
	t_point	*self;

	self = (t_point *)malloc(sizeof(t_point));
	if (!self)
		return (NULL);
	vec3_init(self);
	return (self);
}

void	point_free(t_point *self)
{
	vec3_free(self);
}

void	point_init(t_point *self, double the_x, double the_y, double the_z)
{
	vec3_init_values(self, the_x, the_y, the_z);
}
