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

void	error_bad_file(char *fname, char **errmsg)
{
	char	*aux;

	aux = ft_strjoin("The file  ", fname);
	*errmsg = ft_strjoin(aux, " does not open.");
	free(aux);
}

void	error_bad_scene(char *fname, char **errmsg)
{
	char	*aux;

	aux = ft_strjoin("Scene  ", fname);
	*errmsg = ft_strjoin(aux, " without camera, ambience or light points");
	free(aux);
}
