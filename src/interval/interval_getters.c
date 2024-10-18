/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval_getters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:03:33 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/18 21:05:14 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interval.h"

double	interval_get_min(t_interval *self)
{
	return (self->min);
}

double	interval_get_max(t_interval *self)
{
	return (self->max);
}
