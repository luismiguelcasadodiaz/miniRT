/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_transfer_values_one.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:18:19 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/12 20:57:24 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "libft.h"

void	trans_amb(t_win *w, t_eleme_chunks *chunks, char **errmsg)
{
	t_color	*rgb255;
	float	ambil;

	rgb255 = col_new();
	chunk_init_color(rgb255, &chunks->color, errmsg);
	ambil = trans_atof(chunks->ambil, errmsg);
	if (!col_in_range(rgb255))
		error_bad_color_range(&(chunks->color), errmsg);
	else if (!((0 <= ambil) & (ambil <= 1)))
		error_bad_ambil(chunks->ambil, errmsg);
	else if (w->ambient != NULL)
		error_more_than_one("ambient light", errmsg);
	else
		w->ambient = ambil_set(ambil, rgb255);
	col_free(rgb255);
}

void	trans_cam(t_win *w, t_eleme_chunks *chunks, char **errmsg)
{
	t_vec3	*center;
	t_vec3	*novec;
	float	fview;

	center = vec3_new();
	novec = vec3_new();
	chunk_init_vec3(center, &chunks->coor, errmsg);
	chunk_init_vec3(novec, &chunks->novec, errmsg);
	fview = trans_atof(chunks->fview, errmsg);
	if (!vec3_in_range(novec, -1, 1))
		error_bad_normal_range(&(chunks->line), errmsg);
	else if (vec3_iszero(novec))
		error_normal_zero(&(chunks->novec), errmsg);
	else if (!((HFOV_MIN <= fview) & (fview <= HFOV_MAX)))
		error_bad_fview(chunks->fview, errmsg);
	else if (w->camera != NULL)
		error_more_than_one("camera", errmsg);
	else
		w->camera = camer_set(center, novec, (double) fview);
	vec3_free(novec);
	vec3_free(center);
}

void	trans_lig(t_win *w, t_eleme_chunks *chunks, char **errmsg)
{
	t_vec3	*center;
	float	lbrig;

	center = vec3_new();
	chunk_init_vec3(center, &chunks->coor, errmsg);
	lbrig = trans_atof(chunks->lbrig, errmsg);
	if (!((0 <= lbrig) & (lbrig <= 1)))
		error_bad_lbrig(chunks->fview, errmsg);
	else if (w->light != NULL)
		error_more_than_one("light point", errmsg);
	else
		light_add(&w->light, light_set(center, (double) lbrig));
	vec3_free(center);
}
