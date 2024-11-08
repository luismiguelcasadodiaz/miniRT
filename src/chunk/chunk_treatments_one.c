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

void treat_one_letter_command(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
	if (!ft_strncmp(chunks->line.param[0], "A", 1))
		treat_ambient(chunks, errmsg, w);
	else if (!ft_strncmp(chunks->line.param[0], "C", 1))
		treat_camera(chunks, errmsg, w);
	else if (!ft_strncmp(chunks->line.param[0], "L", 1))
		treat_light(chunks, errmsg, w);
	else
		error_bad_letter_command(&(chunks->line), errmsg);
}

void treat_two_letter_command(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
	if (!ft_strncmp((chunks->line.param[0]), "sp", 2))
		treat_sphere(chunks, errmsg, w);
	else if (!ft_strncmp(chunks->line.param[0], "pl", 2))
		treat_plane(chunks, errmsg, w);
	else if (!ft_strncmp(chunks->line.param[0], "cy", 2))
		treat_cylin(chunks, errmsg, w);
	else
		error_bad_letter_command(&(chunks->line), errmsg);
}

void	treat_ambient(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
    if (chunks->line.num != 3)
        error_bad_number_argumen(&(chunks->line), errmsg);
    else
    {
		error_not_implemented("Ambiente", errmsg);
		trans_sphere(w, chunks, errmsg);
    }

}

void	treat_camera(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
    if (chunks->line.num != 4)
        error_bad_number_argumen(&(chunks->line), errmsg);
    else
    {
        error_not_implemented("Camera", errmsg);
		trans_sphere(w, chunks, errmsg);
    }
}

void	treat_light(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
    if (chunks->line.num != 4)
        error_bad_number_argumen(&(chunks->line), errmsg);
    else
    {
		error_not_implemented("Light", errmsg);
		trans_sphere(w, chunks, errmsg);
    }
}
