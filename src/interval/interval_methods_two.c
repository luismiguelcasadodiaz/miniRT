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

void	int_copy(t_interval *dest, t_interval *orig)
{
	int_set_min(dest, int_get_min(orig));
	int_set_max(dest, int_get_max(orig));
}

void	int_print(t_interval *self)
{
	printf("[%1.4e .. %1.4e]\n", int_get_min(self),
		int_get_max(self));
}
