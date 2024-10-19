/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitrecord_methods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:30:52 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 19:36:26 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitrecord.h"

void	hitrecord_face_normal(t_hitrecord *self, t_ray *ray, t_vec3 *norm)
{
	int	front_face;

	front_face = (vec3_dot(ray_get_dir(ray), norm) < 0);
	if (!front_face)
		vec3_negate(norm, norm);
	hitrecord_set_front_face(self, front_face);
	hitrecord_set_normal(self, norm);
}
