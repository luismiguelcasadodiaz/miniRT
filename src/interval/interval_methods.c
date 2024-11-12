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

double	int_size(t_interval *self)
{
	return (int_get_max(self) - int_get_min(self));
}

bool	int_contains(t_interval *self, double x)
{
	return (int_get_min(self) <= x && x <= int_get_max(self));
}

bool	int_sorrounds(t_interval *self, double x)
{
	return (int_get_min(self) < x && x < int_get_max(self));
}

void	intexpand(t_interval *self, double delta)
{
	int_set_min(self, (int_get_min(self) - (delta / 2.0)));
	int_set_max(self, (int_get_max(self) + (delta / 2.0)));
}

double	int_clamp(t_interval *self, double x)
{
	double	min;
	double	max;

	min = int_get_min(self);
	max = int_get_max(self);
	if (x < min)
		return (min);
	if (max < x)
		return (max);
	return (x);
}
