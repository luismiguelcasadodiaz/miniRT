/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_errors_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:27:11 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/01 16:27:16 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "libft.h"
#include "eleme.h"

void	error_bad_diam(char *diam, char **errmsg, enum e_eleme obj)
{
    char    *aux;

    aux = ft_strjoin("Diameter ", diam);
    if (obj == SPHERE)
        *errmsg = ft_strjoin(aux, " is wrong for a sphere.");
    if (obj == CYLINDER)
        *errmsg = ft_strjoin(aux, " is wrong for a cylinder.");
}

void	error_bad_heig(char *diam, char **errmsg, enum e_eleme obj)
{
    char    *aux;

    aux = ft_strjoin("Height  ", diam);
    if (obj == CYLINDER)
        *errmsg = ft_strjoin(aux, " is wrong for a cylinder..");
    if (obj == CONE)
        *errmsg = ft_strjoin(aux, " is wrong for a cone..");
    free(aux);
}

void	error_bad_normal_num_argu(t_chunk *chunks, char **errmsg)
{
   char    *aux;

    aux = ft_strjoin("The normal for a ", chunks->param[0]);
    *errmsg = ft_strjoin(aux, " has a wrong params number.");
    free(aux);
}

void	error_bad_normal_range(t_chunk *chunks, char **errmsg)
{
   char    *aux;

    aux = ft_strjoin("The normal for ", chunks->param[0]);
    *errmsg = ft_strjoin(aux, " has the coordnates out of range [-1, 1].");
    free(aux);
}

void	error_normal_zero(t_chunk *chunks, char **errmsg)
{
    char    *aux;

    aux = ft_strjoin("THe normal for  ", chunks->param[0]);
    *errmsg = ft_strjoin(aux, " has all coordenates zero. IMPOSIBLE.");
    free(aux);
}
