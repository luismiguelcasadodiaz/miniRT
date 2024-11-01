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


void	error_not_implemented(char *proc, char **errmsg)
{
    *errmsg = ft_strjoin(proc, " No está iimplementado");
}