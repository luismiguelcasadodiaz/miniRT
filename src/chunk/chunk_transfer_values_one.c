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
#include "libft.h"

void	trans_sphere(t_win *w, t_eleme_chunks chunks, char **errmsg)
{
    t_vec3	*center;
	t_color	*rgb255;
	float	diameter;

	center = vec3_new();
	rgb255 = col_new();

	vec3_init_values(center, ft_atof(chunks.coor.param[0]), ft_atof(chunks.coor.param[1]),
        ft_atof(chunks.coor.param[2]));
	col_init_with_255(rgb255, ft_atoi(chunks.color.param[0]), ft_atoi(chunks.color.param[1]),
        ft_atoi(chunks.color.param[2]));
	diameter = ft_atof(chunks.diam);
	if (!col_in_range(rgb255))
		error_bad_color_range(chunks.color, errmsg);
	else if (diameter <= 0)
		error_bad_sp_diam(chunks.diam, errmsg);
	else
		eleme_add(&w->eleme, eleme_new_sph(center, diameter, rgb255));
    col_free(rgb255);
	vec3_free(center);
}