/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:39:31 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/22 23:30:52 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"
#include "ray.h"
#include "interval.h"
#include "hitrecord.h"
#include <stdbool.h>

bool	eleme_hit(t_hit_args *data)
{
	bool		hit_anything;
	t_hit_args	*tem_data;

	tem_data = (t_hit_args *)malloc(sizeof(t_hit_args));
	tem_data->rec = hitrecord_new();
	tem_data->ran = int_new();
	int_init(tem_data->ran, int_get_min(data->ran), int_get_max(data->ran));
	hit_anything = false;
	tem_data->ray = data->ray;
	tem_data->self = data->self;
	while (tem_data->self)
	{
		if ((*tem_data->self->hit)(tem_data))
		{
			hit_anything = true;
			int_init(tem_data->ran, int_get_min(data->ran), tem_data->rec->t);
			hitrecord_copy(data->rec, tem_data->rec);
		}
		tem_data->self = tem_data->self->next;
	}
	hitrecord_free(tem_data->rec);
	int_free(tem_data->ran);
	free(tem_data);
	return (hit_anything);
}
