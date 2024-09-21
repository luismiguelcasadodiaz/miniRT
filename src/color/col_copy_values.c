/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_copy_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:38:32 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/20 20:40:51 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	col_copy_values(t_color *dest, t_color *ori)
{
	vec3_copy_values(dest->rgb, ori->rgb);
	dest->t = ori->t;
	dest->mlx_color = ori->mlx_color;
}
