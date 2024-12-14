/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_transfer_values_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:29:35 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/14 21:29:40 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"

void	trans_lig_bonus(t_win *w, t_eleme_chunks *chunks, char **errmsg)
{
	t_vec3	*center;
	t_color	*rgb255;
	float	lbrig;

	center = vec3_new();
	rgb255 = col_new();
    chunk_init_vec3(center, &chunks->coor, errmsg);
	chunk_init_color(rgb255, &chunks->color);
	lbrig = trans_atof(chunks->lbrig, errmsg);
	if (!col_in_range(rgb255))
		error_bad_color_range(&(chunks->color), errmsg);
	else if (!((0 <= lbrig) & (lbrig <= 1)))
		error_bad_lbrig(chunks->fview, errmsg);
	else
		w->light = light_set_bonus(center, (double) lbrig, rgb255);
	col_free(rgb255);
	vec3_free(center);
}
