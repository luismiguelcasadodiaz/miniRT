/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_errors_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:22:37 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/01 09:24:35 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "libft.h"

void	error_bad_letter_command(t_chunk chunks, char **errmsg)
{
    char    *aux;

    aux = ft_strjoin("El elemento ", chunks.param[0]);
    *errmsg = ft_strjoin(aux, " no es correcto.");
    free(aux);
}

void	error_bad_number_argumen(t_chunk chunks, char **errmsg)
{
    char    *aux;

    aux = ft_strjoin("El elemento ", chunks.param[0]);
    *errmsg = ft_strjoin(aux, " tiene un número incorrecto de parámetros.");
    free(aux);
}

void	error_bad_color_num_argu(t_chunk chunks, char **errmsg)
{
    char    *aux;

    aux = ft_strjoin("El color tiene ", ft_itoa(chunks.num));
    *errmsg = ft_strjoin(aux, " parámetros. Deben de ser tres.");
    free(aux);
}

void	error_bad_point_num_argu(t_chunk chunks, char **errmsg)
{
    char    *aux;

    aux = ft_strjoin("La coordenada tiene ", ft_itoa(chunks.num));
    *errmsg = ft_strjoin(aux, " parámetros. Deben de ser tres.");
    free(aux);
}

void	error_bad_color_range(t_chunk chunks, char **errmsg)
{
    char    *aux;

    aux = ft_strjoin("El color tiene ", ft_itoa(chunks.num));
    *errmsg = ft_strjoin(aux, " parámetros. Deben de ser tres.");
    free(aux);
}

