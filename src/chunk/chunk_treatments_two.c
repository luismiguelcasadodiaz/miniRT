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

void	treat_sphere(t_chunk chunks, char **errmsg, t_win *w)
{
    t_chunk color;
    t_chunk coor;
    float   diameter;

    if (chunks.num != 4)
        error_bad_number_argumen(chunks, errmsg);
    else
    {
        ft_split_minrt(chunks.param[1], ' ', &coor);
        if (coor.num !=3)
            error_bad_point_num_argu(coor, errmsg);
        else
        {
            diameter = ft_atof(chunks.param[2]);
            ft_split_minrt(chunks.param[3], ' ', &color);
            if (color.num !=3)
                error_bad_color_num_argu(color, errmsg);
            else
                trans_sphere(w, coor, diameter, color, errmsg);
        }
    }
}

void	treat_plane(t_chunk chunks, char **errmsg, t_win *w)
{
    if (chunks.num != 4)
        error_bad_number_argumen(chunks, errmsg);
    else
    {
        
    }
}

void	treat_cylin(t_chunk chunks, char **errmsg, t_win *w)
{
    if (chunks.num != 6)
        error_bad_number_argumen(chunks, errmsg);
    else
    {
        
    }
}
