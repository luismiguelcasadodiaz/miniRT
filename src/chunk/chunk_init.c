/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:23:48 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/14 17:58:17 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "libft.h"
#define X 0
#define Y 1
#define Z 2

void	chunk_init_vec3(t_vec3 *v, t_chunk *d, char **errmsg)
{
	vec3_init_values(v, trans_atof(d->param[X], errmsg),
		trans_atof(d->param[Y], errmsg), trans_atof(d->param[Z], errmsg));
}

void	chunk_init_color(t_color *c, t_chunk *d)
{
	col_init_with_255(c, ft_atoi(d->param[X]),
		ft_atoi(d->param[Y]), ft_atoi(d->param[Z]));
}
