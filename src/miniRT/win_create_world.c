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

void	win_world_create(t_eleme *eleme)
{
	t_vec3	*center;
	t_color	*rgb255;

	center = vec3_new();
	rgb255 = col_new();
	vec3_init_values(center, 0, 0, -1);
	col_init_with_255(rgb255, 255, 0, 0);
	eleme_add(&eleme,eleme_new_sph(center, 0.5, rgb255));
	center = vec3_new();
	rgb255 = col_new();
	vec3_init_values(center, 20, 10, -1);
	col_init_with_255(rgb255,0, 255, 0);
	eleme_add(&eleme,eleme_new_sph(center, 0.5, rgb255));
	center = vec3_new();
	rgb255 = col_new();
	vec3_init_values(center, -20, -10, -1);
	col_init_with_255(rgb255,0, 0, 255);
	eleme_add(&eleme,eleme_new_sph(center, 0.5, rgb255));
	eleme_print(eleme);
	col_free(rgb255);
	vec3_free(center);
}

