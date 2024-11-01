/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_treatments_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:53:37 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/01 09:53:53 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "libft.h"

void treat_one_letter_command(t_chunk chunks, char **errmsg, t_win *w)
{
	if (ft_strncmp(chunks.param[0], "A", 1))
		treat_ambient(chunks, errmsg, w);
	else if (ft_strncmp(chunks.param[0], "C", 1))
		treat_camera(chunks, errmsg, w);
	else if (ft_strncmp(chunks.param[0], "L", 1))
		treat_light(chunks, errmsg, w);
	else
		error_bad_letter_command(chunks, errmsg);
}

void treat_two_letter_command(t_chunk chunks, char **errmsg, t_win *w)
{
	if (ft_strncmp(chunks.param[0], "sp", 2))
		treat_sphere(chunks, errmsg, w);
	else if (ft_strncmp(chunks.param[0], "pl", 2))
		treat_plane(chunks, errmsg, w);
	else if (ft_strncmp(chunks.param[0], "cy", 2))
		treat_cylin(chunks, errmsg, w);
	else
		error_bad_letter_command(chunks, errmsg);
}

void	treat_ambient(t_chunk chunks, char **errmsg, t_win *w)
{
    if (chunks.num != 3)
        error_bad_number_argumen(chunks, errmsg);
    else
    {

    }

}

void	treat_camera(t_chunk chunks, char **errmsg, t_win *w)
{
    if (chunks.num != 4)
        error_bad_number_argumen(chunks, errmsg);
    else
    {
        
    }
}

void	treat_light(t_chunk chunks, char **errmsg, t_win *w)
{
    if (chunks.num != 4)
        error_bad_number_argumen(chunks, errmsg);
    else
    {

    }
}
