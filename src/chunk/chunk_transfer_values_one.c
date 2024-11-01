/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_transfer_values_one.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:18:19 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/01 11:18:54 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"

void	trans_sphere(t_win *w, t_chunk coor, double diameter, t_chunk color)
{
    t_vec3	*center;
	t_color	*rgb255;
	t_vec3	*novec;

	center = vec3_new();
	rgb255 = col_new();
	novec = vec3_new();
	vec3_init_values(center, ft_atof(coor.param[0]), ft_atof(coor.param[1]),
        ft_atof(coor.param[2]));
	col_init_with_255(rgb255, ft_atoi(color.param[0]), ft_atoi(color.param[1]),
        ft_atoi(color.param[2]));
	eleme_add(*(&w->eleme), eleme_new_sph(center, diameter, rgb255));
    col_free(rgb255);
	vec3_free(center);
	vec3_free(novec);
}