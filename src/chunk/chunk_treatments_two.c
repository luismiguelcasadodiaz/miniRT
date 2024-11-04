/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_treatments_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:54:01 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/01 09:54:22 by luicasad         ###   ########.fr       */
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

void	treat_sphere(t_eleme_chunks chunks, char **errmsg, t_win *w)
{
    if (chunks.line.num != 4)
        error_bad_number_argumen(chunks.line, errmsg);
    else
    {
        ft_split_minrt(chunks.line.param[SP_CENT], ',', &chunks.coor);
        if (chunks.coor.num !=3)
            error_bad_point_num_argu(chunks.coor, errmsg);
        else
        {
            chunks.diam = chunks.line.param[SP_DIAM];
            ft_split_minrt(chunks.line.param[SP_COLO], ',', &chunks.color);
            if (chunks.color.num !=3)
                error_bad_color_num_argu(chunks.color, errmsg);
            else
                trans_sphere(w, chunks, errmsg);
        }
    }
}

void	treat_plane(t_eleme_chunks chunks, char **errmsg, t_win *w)
{
    if (chunks.line.num != 4)
        error_bad_number_argumen(chunks.line, errmsg);
    else
    {
        ft_split_minrt(chunks.line.param[PL_CENT], ',', &chunks.coor);
        if (chunks.coor.num !=3)
            error_bad_point_num_argu(chunks.coor, errmsg);
        else
        {
            ft_split_minrt(chunks.line.param[PL_VECT], ',', &chunks.novec);
            if (chunks.novec.num != 3)
                error_normal_bad_num_argu(chunks.novec, errmsg);
            else
            {
                ft_split_minrt(chunks.line.param[PL_COLO], ',', &chunks.color);
                if (chunks.novec.num != 3)
                    error_bad_color_num_argu(chunks.color, errmsg);
                else
                    trans_plane(w, chunks, errmsg);
            }
        }
    }
}

void	treat_cylin(t_eleme_chunks chunks, char **errmsg, t_win *w)
{
    if (chunks.line.num != 6)
        error_bad_number_argumen(chunks.line, errmsg);
    else
    {
        ft_split_minrt(chunks.line.param[CY_CENT], ',', &chunks.coor);
        if (chunks.coor.num !=3)
            error_bad_point_num_argu(chunks.coor, errmsg);
        else
        {
            ft_split_minrt(chunks.line.param[CY_VECT], ',', &chunks.novec);
            if (chunks.novec.num != 3)
                error_normal_bad_num_argu(chunks.novec, errmsg);
            else
            {
                chunks.diam = chunks.line.param[CY_DIAM];
                chunks.diam = chunks.line.param[CY_HEIG];
                ft_split_minrt(chunks.line.param[CY_COLO], ',', &chunks.color);
                if (chunks.color.num != 3)
                    error_normal_bad_num_argu(chunks.novec, errmsg);
                else
                    trans_cylin(w, chunks, errmsg);
            }
        }
    }
}
