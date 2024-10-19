/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 09:10:41 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 11:18:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interval.h"
#include <stdlib.h>
#define DBL_MAX 1.7976931348623157E+308 

t_interval	*interval_new(void)
{
	t_interval	*self;

	self = (t_interval *)malloc(sizeof(t_interval));
	if (!self)
		return (NULL);
	interval_set_min(self, 0);
	interval_set_max(self, 0);
	return (self);
}

void	interval_free(t_interval *self)
{
	interval_set_min(self, 0);
	interval_set_max(self, 0);
	free(self);
}

void	interval_init(t_interval *self, double min, double max)
{
	interval_set_min(self, min);
	interval_set_max(self, max);
}

/* tested with .....

	printf(" DBL_MAX %lf\n\n", DBL_MAX);
	printf(" DBL_MIN %lf\n\n", DBL_MIN);
	printf("-DBL_MAX %lf\n\n", -DBL_MAX);

 DBL_MAX  179769313486231570814527423731704356798070567525844996598917476803157
2607800285387605895586327668781715404589535143824642343213268894641827684675467
0353751698604991057655128207624549009038932894407586850845513394230458323690322
2948165808559332123348274797826204144723168738177180919299881250404026184124858
368.000000

 DBL_MIN 0.000000

-DBL_MAX -179769313486231570814527423731704356798070567525844996598917476803157
2607800285387605895586327668781715404589535143824642343213268894641827684675467
0353751698604991057655128207624549009038932894407586850845513394230458323690322
2948165808559332123348274797826204144723168738177180919299881250404026184124858
368.000000*
*/

// +infinity .. - infinity
void	interval_init_empty(t_interval *self)
{
	interval_set_min(self, DBL_MAX);
	interval_set_max(self, -DBL_MAX);
}

// -infinity .. +infinity
void	interval_init_universe(t_interval *self)
{
	interval_set_min(self, -DBL_MAX);
	interval_set_max(self, DBL_MAX);
}
