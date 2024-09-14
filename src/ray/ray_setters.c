/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:13:25 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/13 08:17:04 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_set_orig(t_ray *self, t_point *the_orig)
{
	self->orig = the_orig;
}

void	ray_set_dir(t_ray *self, t_vec3 *the_dir)
{
	self->dir = the_dir;
}
