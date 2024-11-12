/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval_setters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:00:30 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/18 21:02:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interval.h"

void	int_set_min(t_interval *self, double min)
{
	self->min = min;
}

void	int_set_max(t_interval *self, double max)
{
	self->max = max;
}
