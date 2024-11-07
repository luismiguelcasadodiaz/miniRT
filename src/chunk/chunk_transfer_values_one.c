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
#define X 0
#define Y 1
#define Z 2

void	trans_sphere(t_win *w, t_eleme_chunks chunks, char **errmsg)
{
    t_vec3	*center;
	t_color	*rgb255;
	float	diameter;

	center = vec3_new();
	rgb255 = col_new();

	vec3_init_values(center, ft_atof(chunks.coor.param[X]), ft_atof(chunks.coor.param[Y]),
        ft_atof(chunks.coor.param[Z]));
	col_init_with_255(rgb255, ft_atoi(chunks.color.param[X]), ft_atoi(chunks.color.param[Y]),
        ft_atoi(chunks.color.param[Z]));
	diameter = ft_atof(chunks.diam);
	if (!col_in_range(rgb255))
		error_bad_color_range(chunks.color, errmsg);
	else if (diameter <= 0)
		error_bad_diam(chunks.diam, errmsg, SPHERE);
	else
		eleme_add(&w->eleme, eleme_new_sph(center, diameter, rgb255));
    col_free(rgb255);
	vec3_free(center);
}

void	trans_plane(t_win *w, t_eleme_chunks chunks, char **errmsg)
{
    t_vec3	*center;
	t_vec3	*novec;
	t_color	*rgb255;


	center = vec3_new();
	novec = vec3_new();
	rgb255 = col_new();
	vec3_init_values(center, ft_atof(chunks.coor.param[X]), ft_atof(chunks.coor.param[Y]),
        ft_atof(chunks.coor.param[Z]));
	vec3_init_values(novec, ft_atof(chunks.novec.param[X]), ft_atof(chunks.novec.param[Y]),
        ft_atof(chunks.novec.param[Z]));
	col_init_with_255(rgb255, ft_atoi(chunks.color.param[X]), ft_atoi(chunks.color.param[Y]),
        ft_atoi(chunks.color.param[Z]));
	if (!col_in_range(rgb255))
		error_bad_color_range(chunks.color, errmsg);
	else if (!vec3_in_range(novec, -1, 1))
		error_normal_bad_range(chunks.novec, errmsg);
	else if (vec3_iszero(novec))
		error_normal_zero(chunks.novec, errmsg);
	else
		eleme_add(&w->eleme, eleme_new_pla(center, novec, rgb255));
    col_free(rgb255);
	vec3_free(novec);
	vec3_free(center);
}

void	trans_cylin(t_win *w, t_eleme_chunks chunks, char **errmsg)
{
    t_vec3	*center;
	t_vec3	*novec;
	t_color	*rgb255;
	t_vec3	*h_and_d;

	center = vec3_new();
	novec = vec3_new();
	rgb255 = col_new();
	h_and_d = vec3_new();
	vec3_init_values(center, ft_atof(chunks.coor.param[X]), ft_atof(chunks.coor.param[Y]),
        ft_atof(chunks.coor.param[Z]));
	vec3_init_values(novec, ft_atof(chunks.novec.param[X]), ft_atof(chunks.novec.param[Y]),
        ft_atof(chunks.novec.param[Z]));
	vec3_init_values(h_and_d, ft_atof(chunks.diam), ft_atof(chunks.height), 0.0);
	col_init_with_255(rgb255, ft_atoi(chunks.color.param[X]), ft_atoi(chunks.color.param[Y]),
        ft_atoi(chunks.color.param[Z]));
	if (!col_in_range(rgb255))
		error_bad_color_range(chunks.color, errmsg);
	else if (!vec3_in_range(novec, -1, 1))
		error_normal_bad_range(chunks.novec, errmsg);
	else if (vec3_iszero(novec))
		error_normal_zero(chunks.novec, errmsg);
	else if (h_and_d->e[0] <= 0)
		error_bad_diam(chunks.diam, errmsg, CYLINDER);
	else if (h_and_d->e[1] <= 0)
		error_bad_heig(chunks.height, errmsg, CYLINDER);
	else
		eleme_add(&w->eleme, eleme_new_cyl(center, novec, h_and_d, rgb255));
    vec3_free(h_and_d);
	col_free(rgb255);
	vec3_free(novec);
	vec3_free(center);
}