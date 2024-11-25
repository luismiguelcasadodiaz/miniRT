/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_errors_four.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:49:19 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/18 16:49:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "libft.h"


void	error_more_than_one(char *object, char **errmsg)
{
	char	*aux;

	aux = ft_strjoin("This scene defines more than one ", object);
	*errmsg = ft_strjoin(aux, ". That does not follows the mandatory subject.");
	free(aux);
}
