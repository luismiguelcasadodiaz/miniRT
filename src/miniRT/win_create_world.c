/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_create_world.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:26:21 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/21 18:38:50 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	win_world_create(t_eleme **eleme)
{
	t_vec3	*center;
	t_color	*rgb255;
	t_vec3	*novec;

	center = vec3_new();
	rgb255 = col_new();
	novec = vec3_new();
	vec3_init_values(center, 0, 0, -1);
	col_init_with_255(rgb255, 255, 0, 0);
	eleme_add(*(&eleme), eleme_new_sph(center, 0.5, rgb255));
	vec3_init_values(center, 0, 0.2, -1);
	col_init_with_255(rgb255, 51, 255, 51);
	eleme_add(*(&eleme), eleme_new_sph(center, 0.3, rgb255));
	vec3_init_values(center, 0.2, 0, -0.5);
	col_init_with_255(rgb255, 0, 255, 255);
	eleme_add(*(&eleme), eleme_new_sph(center, 0.2, rgb255));
	eleme_print(*eleme);
	vec3_init_values(center, -0.3, 0, -1.5);
	col_init_with_255(rgb255, 255, 255, 0);
	eleme_add(*(&eleme), eleme_new_sph(center, 0.5, rgb255));
	vec3_init_values(center, 0, -50.5, -1);
	col_init_with_255(rgb255, 0, 255, 0);
	eleme_add(*(&eleme), eleme_new_sph(center, 100, rgb255));
	vec3_init_values(center, -3, 3, -5);
	col_init_with_255(rgb255, 255, 255, 0);
	vec3_init_values(novec, 0, 0, 0);
	eleme_add(*(&eleme), eleme_new_pla(center, novec, rgb255));
	col_free(rgb255);
	vec3_free(center);
	vec3_free(novec);
}
