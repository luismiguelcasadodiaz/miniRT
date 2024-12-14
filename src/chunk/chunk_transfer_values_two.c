/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_transfer_values_two.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:18:19 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/14 17:56:57 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"

void	trans_sph(t_win *w, t_eleme_chunks *chunks, char **errmsg)
{
	t_vec3	*center;
	t_color	*rgb255;
	float	diameter;

	center = vec3_new();
	rgb255 = col_new();
	chunk_init_vec3(center, &chunks->coor, errmsg);
	chunk_init_color(rgb255, &chunks->color, errmsg);
	diameter = trans_atof(chunks->diam, errmsg);
	if (!col_in_range(rgb255))
		error_bad_color_range(&(chunks->color), errmsg);
	else if (diameter <= 0)
		error_bad_diam(chunks->diam, errmsg, SPHERE);
	else
		eleme_add(&w->eleme, eleme_new_sph(center, diameter, rgb255));
	col_free(rgb255);
	vec3_free(center);
}

void	trans_pla(t_win *w, t_eleme_chunks *chunks, char **errmsg)
{
	t_vec3	*center;
	t_vec3	*novec;
	t_color	*rgb255;

	center = vec3_new();
	novec = vec3_new();
	rgb255 = col_new();
	chunk_init_vec3(center, &chunks->coor, errmsg);
	chunk_init_vec3(novec, &chunks->novec, errmsg);
	chunk_init_color(rgb255, &chunks->color, errmsg);
	if (!col_in_range(rgb255))
		error_bad_color_range(&(chunks->color), errmsg);
	else if (!vec3_in_range(novec, -1, 1))
		error_bad_normal_range(&(chunks->line), errmsg);
	else if (vec3_iszero(novec))
		error_normal_zero(&(chunks->novec), errmsg);
	else
		eleme_add(&w->eleme, eleme_new_pla(center, novec, rgb255));
	col_free(rgb255);
	vec3_free(novec);
	vec3_free(center);
}

static void	free_cnrh(t_vec3 *cen, t_vec3 *nov, t_color *rgb255, t_vec3 *h)
{
	vec3_free(h);
	col_free(rgb255);
	vec3_free(nov);
	vec3_free(cen);
}

static int	good_dia_height(t_eleme_chunks *chunks, t_vec3 *h_d, char **errmsg)
{
	if (h_d->e[0] <= 0)
	{
		error_bad_diam(chunks->diam, errmsg, CYLINDER);
		return (0);
	}
	else if (h_d->e[1] <= 0)
	{
		error_bad_heig(chunks->height, errmsg, CYLINDER);
		return (0);
	}
	return (1);
}

void	trans_cyl(t_win *w, t_eleme_chunks *chunks, char **errmsg)
{
	t_vec3	*center;
	t_vec3	*novec;
	t_color	*rgb255;
	t_vec3	*h_d;

	center = vec3_new();
	novec = vec3_new();
	rgb255 = col_new();
	h_d = vec3_new();
	vec3_init_values(h_d, trans_atof(chunks->diam, errmsg),
		trans_atof(chunks->height, errmsg), 0.0);
	chunk_init_vec3(center, &chunks->coor, errmsg);
	chunk_init_vec3(novec, &chunks->novec, errmsg);
	chunk_init_color(rgb255, &chunks->color, errmsg);
	if (!col_in_range(rgb255))
		error_bad_color_range(&(chunks->color), errmsg);
	else if (!vec3_in_range(novec, -1, 1))
		error_bad_normal_range(&(chunks->line), errmsg);
	else if (vec3_iszero(novec))
		error_normal_zero(&(chunks->novec), errmsg);
	else if (good_dia_height(chunks, h_d, errmsg))
		eleme_add(&w->eleme, eleme_new_cyl(center, novec, h_d, rgb255));
	free_cnrh(center, novec, rgb255, h_d);
}
