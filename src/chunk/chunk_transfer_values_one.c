/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_transfer_values_one.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:18:19 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/13 17:35:18 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "libft.h"
#define X 0
#define Y 1
#define Z 2

void	trans_amb(t_win *w, t_eleme_chunks *chunks, char **errmsg)
{
	t_color	*rgb255;
	float	ambil;

	rgb255 = col_new();
	col_init_with_255(rgb255, ft_atoi(chunks->color.param[X]),
		ft_atoi(chunks->color.param[Y]), ft_atoi(chunks->color.param[Z]));
	ambil = ft_atof(chunks->ambil);
	if (!col_in_range(rgb255))
		error_bad_color_range(&(chunks->color), errmsg);
	else if (!((0 <= ambil) & (ambil <= 1)))
		error_bad_ambil(chunks->ambil, errmsg);
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
	vec3_init_values(center, ft_atof(chunks->coor.param[X]),
		ft_atof(chunks->coor.param[Y]), ft_atof(chunks->coor.param[Z]));
	vec3_init_values(novec, ft_atof(chunks->novec.param[X]),
		ft_atof(chunks->novec.param[Y]), ft_atof(chunks->novec.param[Z]));
	fview = ft_atof(chunks->fview);
	if (!vec3_in_range(novec, -1, 1))
		error_bad_normal_range(&(chunks->line), errmsg);
	else if (vec3_iszero(novec))
		error_normal_zero(&(chunks->novec), errmsg);
	else if (!((0 <= fview) & (fview <= 180)))
		error_bad_fview(chunks->fview, errmsg);
	else
		w->camera = camer_set(center, novec, (double) fview, w);
	vec3_free(novec);
	vec3_free(center);
}

void	trans_lig(t_win *w, t_eleme_chunks *chunks, char **errmsg)
{
	t_vec3	*center;
	float	lbrig;

	center = vec3_new();
	vec3_init_values(center, ft_atof(chunks->coor.param[X]),
		ft_atof(chunks->coor.param[Y]), ft_atof(chunks->coor.param[Z]));
	lbrig = ft_atof(chunks->lbrig);
	if (!((0 <= lbrig) & (lbrig <= 1)))
		error_bad_lbrig(chunks->fview, errmsg);
	else
		light_add(&w->light, light_set(center, (double) lbrig));
	vec3_free(center);
}

void	trans_lig_bonus(t_win *w, t_eleme_chunks *chunks, char **errmsg)
{
	t_vec3	*center;
	t_color	*rgb255;
	float	lbrig;

	center = vec3_new();
	rgb255 = col_new();
	vec3_init_values(center, ft_atof(chunks->coor.param[X]),
		ft_atof(chunks->coor.param[Y]), ft_atof(chunks->coor.param[Z]));
	col_init_with_255(rgb255, ft_atoi(chunks->color.param[X]),
		ft_atoi(chunks->color.param[Y]), ft_atoi(chunks->color.param[Z]));
	lbrig = ft_atof(chunks->lbrig);
	if (!col_in_range(rgb255))
		error_bad_color_range(&(chunks->color), errmsg);
	else if (!((0 <= lbrig) & (lbrig <= 1)))
		error_bad_lbrig(chunks->fview, errmsg);
	else
		w->light = light_set_bonus(center, (double) lbrig, rgb255);
	col_free(rgb255);
	vec3_free(center);
}
