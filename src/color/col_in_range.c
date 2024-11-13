/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_in_range.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:04:01 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/13 18:05:03 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	col_in_range(t_color *self)
{
	int	result;

	result = ((0 <= self->rgb->e[0]) && (self->rgb->e[0] <= 1));
	result = result && ((0 <= self->rgb->e[1]) && (self->rgb->e[1] <= 1));
	result = result && ((0 <= self->rgb->e[2]) && (self->rgb->e[2] <= 1));
	return (result);
}
