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

void	treat_sphere(t_eleme_chunks chunks, char **errmsg, t_win *w)
{
    if (chunks.line.num != 4)
        error_bad_number_argumen(chunks.line, errmsg);
    else
    {
        ft_split_minrt(chunks.line.param[1], ',', &chunks.coor);
        if (chunks.coor.num !=3)
            error_bad_point_num_argu(chunks.coor, errmsg);
        else
        {
            chunks.diam = chunks.line.param[2];
            ft_split_minrt(chunks.line.param[3], ',', &chunks.color);
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
     		error_not_implemented("Plane", errmsg);   
            trans_sphere(w, chunks, errmsg);
    }
}

void	treat_cylin(t_eleme_chunks chunks, char **errmsg, t_win *w)
{
    if (chunks.line.num != 6)
        error_bad_number_argumen(chunks.line, errmsg);
    else
    {
        error_not_implemented("Cylinder", errmsg);
        trans_sphere(w, chunks, errmsg);
    }
}
