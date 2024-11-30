/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_treatments_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:54:01 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/13 17:38:48 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "libft.h"

#define SP_CENT 1
#define SP_DIAM 2
#define SP_COLO 3
#define PL_CENT 1
#define PL_VECT 2
#define PL_COLO 3
#define CY_CENT 1
#define CY_VECT 2
#define CY_DIAM 3
#define CY_HEIG 4
#define CY_COLO 5

void	treat_sph(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
	if (chunks->line.num != 4)
		error_bad_number_argumen(&(chunks->line), errmsg);
	else
	{
		ft_split_minrt(chunks->line.param[SP_CENT], ",", &(chunks->coor));
		ft_split_minrt(chunks->line.param[SP_COLO], ",", &chunks->color);
		if (chunks->coor.num != 3)
			error_bad_point_num_argu(&(chunks->coor), errmsg);
		else if (chunks->color.num != 3)
			error_bad_color_num_argu(&(chunks->color), errmsg);
		else
		{
			chunks->diam = chunks->line.param[SP_DIAM];
			trans_sph(w, chunks, errmsg);
		}
		de_allocate(chunks->coor.param, chunks->coor.num);
		de_allocate(chunks->color.param, chunks->color.num);
	}
}

void	treat_pla(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
	if (chunks->line.num != 4)
		error_bad_number_argumen(&(chunks->line), errmsg);
	else
	{
		ft_split_minrt(chunks->line.param[PL_CENT], ",", &(chunks->coor));
		ft_split_minrt(chunks->line.param[PL_VECT], ",", &(chunks->novec));
		ft_split_minrt(chunks->line.param[PL_COLO], ",", &(chunks->color));
		if (chunks->coor.num != 3)
			error_bad_point_num_argu(&(chunks->coor), errmsg);
		else if (chunks->novec.num != 3)
			error_bad_normal_num_argu(&(chunks->novec), errmsg);
		else if (chunks->color.num != 3)
			error_bad_color_num_argu(&(chunks->color), errmsg);
		else
			trans_pla(w, chunks, errmsg);
		de_allocate(chunks->coor.param, chunks->coor.num);
		de_allocate(chunks->novec.param, chunks->novec.num);
		de_allocate(chunks->color.param, chunks->color.num);
	}
}

void	treat_cyl(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
	if (chunks->line.num != 6)
		error_bad_number_argumen(&(chunks->line), errmsg);
	else
	{
		ft_split_minrt(chunks->line.param[CY_CENT], ",", &chunks->coor);
		ft_split_minrt(chunks->line.param[CY_VECT], ",", &chunks->novec);
		ft_split_minrt(chunks->line.param[CY_COLO], ",", &chunks->color);
		if (chunks->coor.num != 3)
			error_bad_point_num_argu(&(chunks->coor), errmsg);
		else if (chunks->novec.num != 3)
			error_bad_normal_num_argu(&(chunks->novec), errmsg);
		else if (chunks->color.num != 3)
			error_bad_color_num_argu(&(chunks->novec), errmsg);
		else
		{
			chunks->diam = chunks->line.param[CY_DIAM];
			chunks->height = chunks->line.param[CY_HEIG];
			trans_cyl(w, chunks, errmsg);
		}
		de_allocate(chunks->coor.param, chunks->coor.num);
		de_allocate(chunks->novec.param, chunks->novec.num);
		de_allocate(chunks->color.param, chunks->color.num);
	}
}
