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

    aux = ft_strjoin("El diámetro ", diam);
    if (obj == SPHERE)
        *errmsg = ft_strjoin(aux, " no es correcto para la esfera.");
    if (obj == CYLINDER)
        *errmsg = ft_strjoin(aux, " no es correcto para el cilindro.");
    free(aux);
}

void	error_bad_heig(char *diam, char **errmsg, enum e_eleme obj)
{
    char    *aux;

    aux = ft_strjoin("La altura ", diam);
    if (obj == CYLINDER)
        *errmsg = ft_strjoin(aux, " no es correcta para el cilindro.");
    if (obj == CONE)
        *errmsg = ft_strjoin(aux, " no es correcta para el cono.");
    free(aux);
}

void	error_normal_bad_num_argu(t_chunk *chunks, char **errmsg)
{
   char    *aux;

    aux = ft_strjoin("La normal del ", chunks->param[0]);
    *errmsg = ft_strjoin(aux, " tiene un número incorrecto de parámetros.");
    free(aux);
}

void	error_normal_bad_range(t_chunk *chunks, char **errmsg)
{
   char    *aux;

    aux = ft_strjoin("La normal del ", chunks->param[0]);
    *errmsg = ft_strjoin(aux, " tiene coordenadas fuera del intervalo [-1, 1].");
    free(aux);
}

void	error_normal_zero(t_chunk *chunks, char **errmsg)
{
    char    *aux;

    aux = ft_strjoin("La normal del ", chunks->param[0]);
    *errmsg = ft_strjoin(aux, " tiene todas las coordenadas nulas. IMPOSIBLE.");
    free(aux);
}

void	error_not_implemented(char *proc, char **errmsg)
{
    *errmsg = ft_strjoin(proc, " No está iimplementado");
}