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

#define A_AMBI 1
#define A_COLO 2
#define C_COOR 1
#define C_NOVE 2
#define C_FVIE 3
#define L_COOR 1
#define L_BRIG 2
#define L_COLO 3


void treat_one_letter_command(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
	if (!ft_strncmp(chunks->line.param[0], "A", 1))
		treat_amb(chunks, errmsg, w);
	else if (!ft_strncmp(chunks->line.param[0], "C", 1))
		treat_cam(chunks, errmsg, w);
	else if (!ft_strncmp(chunks->line.param[0], "L", 1))
		treat_lig(chunks, errmsg, w);
	else
		error_bad_letter_command(&(chunks->line), errmsg);
}

void treat_two_letter_command(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
	if (!ft_strncmp((chunks->line.param[0]), "sp", 2))
		treat_sph(chunks, errmsg, w);
	else if (!ft_strncmp(chunks->line.param[0], "pl", 2))
		treat_pla(chunks, errmsg, w);
	else if (!ft_strncmp(chunks->line.param[0], "cy", 2))
		treat_cyl(chunks, errmsg, w);
	else
		error_bad_letter_command(&(chunks->line), errmsg);
}

void	treat_amb(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
    if (chunks->line.num != 3)
        error_bad_number_argumen(&(chunks->line), errmsg);
    else
    {
		ft_split_minrt(chunks->line.param[A_COLO], ',', &(chunks->color));
		if (chunks->color.num !=3)
            error_bad_color_num_argu(&(chunks->color), errmsg);
		else
		{
			chunks->ambil = chunks->line.param[A_AMBI];
			trans_sph(w, chunks, errmsg);
		}
		de_allocate(chunks->color.param, chunks->color.num);
    }

}

void	treat_cam(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
    if (chunks->line.num != 4)
        error_bad_number_argumen(&(chunks->line), errmsg);
    else
    {
        ft_split_minrt(chunks->line.param[C_COOR], ',', &(chunks->coor));
		ft_split_minrt(chunks->line.param[C_NOVE], ',', &(chunks->novec));
        if (chunks->coor.num !=3)
            error_bad_point_num_argu(&(chunks->coor), errmsg);
        else if (chunks->novec.num !=3)
            error_bad_normal_num_argu(&(chunks->novec), errmsg);
        else
        {
		chunks->fview = chunks->line.param[C_FVIE];
		trans_cam(w, chunks, errmsg);
    	}
		de_allocate(chunks->coor.param, chunks->coor.num);
		de_allocate(chunks->novec.param, chunks->novec.num);
	}
}
// THis funtion changes in the bonus to the one commented below
void	treat_lig(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
    if (chunks->line.num != 3)
        error_bad_number_argumen(&(chunks->line), errmsg);
    else
    {
		ft_split_minrt(chunks->line.param[L_COOR], ',', &(chunks->coor));
        if (chunks->coor.num !=3)
            error_bad_point_num_argu(&(chunks->coor), errmsg);
        else
        {
			chunks->lbrig = chunks->line.param[L_BRIG];
			trans_lig(w, chunks, errmsg);
    	}
		de_allocate(chunks->coor.param, chunks->coor.num);
	}
}

/*
void	treat_lig(t_eleme_chunks *chunks, char **errmsg, t_win *w)
{
    if (chunks->line.num != 4)
        error_bad_number_argumen(&(chunks->line), errmsg);
    else
    {
		ft_split_minrt(chunks->line.param[L_COOR], ',', &(chunks->coor));
		ft_split_minrt(chunks->line.param[L_COLO], ',', &(chunks->color));
        if (chunks->coor.num !=3)
            error_bad_point_num_argu(&(chunks->coor), errmsg);
        else if (chunks->color.num !=3)
            error_bad_color_num_argu(&(chunks->color), errmsg);
        else
        {
			chunks->lbrig = chunks->line.param[L_BRIG];
			trans_lig(w, chunks, errmsg);
    	}
		de_allocate(chunks->coor.param, chunks->coor.num);
		de_allocate(chunks->color.param, chunks->color.num);
	}
}


*/