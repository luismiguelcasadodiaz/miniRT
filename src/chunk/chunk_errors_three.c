/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_errors_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:27:11 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/13 17:13:31 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "libft.h"
#include "eleme.h"

void	error_bad_ambil(char *ambil, char **errmsg)
{
	char	*aux;

	aux = ft_strjoin("Ambient light ratio value ", ambil);
	*errmsg = ft_strjoin(aux, " is incorrect.");
	free(aux);
}

void	error_bad_fview(char *fview, char **errmsg)
{
	char	*aux;

	aux = ft_strjoin("Horizontal fiels of view value ", fview);
	*errmsg = ft_strjoin(aux, " is incorrect.");
	free(aux);
}

void	error_bad_lbrig(char *lbrig, char **errmsg)
{
	char	*aux;

	aux = ft_strjoin("Horizontal fiels of view value ", lbrig);
	*errmsg = ft_strjoin(aux, " is incorrect.");
	free(aux);
}

void	error_not_implemented(char *proc, char **errmsg)
{
	*errmsg = ft_strjoin(proc, " No está iimplementado");
}
