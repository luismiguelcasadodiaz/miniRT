/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_errors_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:22:37 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/12 20:59:35 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "libft.h"

void	error_bad_letter_command(t_chunk *chunks, char **errmsg)
{
	char	*aux;

	if (*errmsg != NULL)
		return ;
	aux = ft_strjoin("The element ", chunks->param[0]);
	*errmsg = ft_strjoin(aux, " is incorrect.");
	free(aux);
}

void	error_bad_number_argumen(t_chunk *chunks, char **errmsg)
{
	char	*aux;

	if (*errmsg != NULL)
		return ;
	aux = ft_strjoin("The element ", chunks->param[0]);
	*errmsg = ft_strjoin(aux, " has a wrong params number.");
	free(aux);
}

void	error_bad_color_num_argu(t_chunk *chunks, char **errmsg)
{
	char	*aux;
	char	*num;

	if (*errmsg != NULL)
		return ;
	num = ft_itoa(chunks->num);
	aux = ft_strjoin("RGB Color definition has ", num);
	*errmsg = ft_strjoin(aux, " parameters. Must be 3.");
	free(aux);
	free(num);
}

void	error_bad_point_num_argu(t_chunk *chunks, char **errmsg)
{
	char	*aux;
	char	*num;

	if (*errmsg != NULL)
		return ;
	num = ft_itoa(chunks->num);
	aux = ft_strjoin("The coordinate definition has ", num);
	*errmsg = ft_strjoin(aux, " parámeter. Must be 3.");
	free(aux);
	free(num);
}

void	error_bad_color_range(t_chunk *chunks, char **errmsg)
{
	char	*aux;
	char	*num;

	if (*errmsg != NULL)
		return ;
	num = ft_itoa(chunks->num);
	aux = ft_strjoin("Values defining color ", num);
	*errmsg = ft_strjoin(aux, " are wrong. expected range is [0..255].");
	free(aux);
	free(num);
}
