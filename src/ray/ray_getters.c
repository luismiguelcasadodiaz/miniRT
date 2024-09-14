/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_getters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:17:39 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/13 08:20:44 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_point	*ray_get_orig(t_ray *self)
{
	return (self->orig);
}

t_vec3	*ray_get_dir(t_ray *self)
{
	return (self->dir);
}
