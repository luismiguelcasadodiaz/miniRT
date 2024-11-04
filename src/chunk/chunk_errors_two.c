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

void	error_bad_sp_diam(char *diam, char **errmsg)
{
    char    *aux;

    aux = ft_strjoin("El diámetro ", diam);
    *errmsg = ft_strjoin(aux, " no es correcto para la esfera.");
    free(aux);
}

void	error_normal_bad_num_argu(t_chunk chunks, char **errmsg)
{
   char    *aux;

    aux = ft_strjoin("La normal del ", chunks.param[0]);
    *errmsg = ft_strjoin(aux, " tiene un número incorrecto de parámetros.");
    free(aux);
}

void	error_normal_bad_range(t_chunk chunks, char **errmsg)
{
   char    *aux;

    aux = ft_strjoin("La normal del ", chunks.param[0]);
    *errmsg = ft_strjoin(aux, " tiene coordenadas fuera del intervalo [-1, 1].");
    free(aux);
}

void	error_normal_zero(t_chunk chunks, char **errmsg)
{
    char    *aux;

    aux = ft_strjoin("La normal del ", chunks.param[0]);
    *errmsg = ft_strjoin(aux, " tiene todas las coordenadas nulas. IMPOSIBLE.");
    free(aux);
}

void	error_not_implemented(char *proc, char **errmsg)
{
    *errmsg = ft_strjoin(proc, " No está iimplementado");
}