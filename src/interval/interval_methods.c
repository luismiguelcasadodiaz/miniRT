/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval_methods.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:07:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/18 21:23:57 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interval.h"

double	interval_size(t_interval *self)
{
	return (interval_get_max(self) - interval_get_min(self));
}

bool	interval_contains(t_interval *self, double x)
{
	return (interval_get_min(self) <= x && x <= interval_get_max(self));
}

bool	interval_sorrounds(t_interval *self, double x)
{
	return (interval_get_min(self) < x && x < interval_get_max(self));
}

void	interval_expand(t_interval *self, double delta)
{
	interval_set_min(self, (interval_get_min(self) - (delta / 2.0)));
	interval_set_max(self, (interval_get_max(self) + (delta / 2.0)));
}

double	interval_clamp(t_interval *self, double x)
{
	double	min;
	double	max;

	min = interval_get_min(self);
	max = interval_get_max(self);
	if (x < min)
		return (min);
	if (max < x)
		return (max);
	return (x);
}
