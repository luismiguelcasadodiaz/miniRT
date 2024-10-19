/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval_methods_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:17:57 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 11:44:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interval.h"
#include <stdio.h>

void	interval_copy(t_interval *dest, t_interval *orig)
{
	interval_set_min(dest, interval_get_min(orig));
	interval_set_max(dest, interval_get_max(orig));
}

void	interval_print(t_interval *self)
{
	printf("[%1.4e .. %1.4e]\n", interval_get_min(self),
		interval_get_max(self));
}
