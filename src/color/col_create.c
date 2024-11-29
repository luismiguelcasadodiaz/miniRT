/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:06 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/14 08:51:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "color.h"

t_color	*col_new(void)
{
	t_color	*self;

	self = (t_color *)malloc(sizeof(t_color));
	if (!self)
		return (NULL);
	vec3_init(&self->rgb);
	self->t = 0;
	col_init_with_1(self, 0.0, 0.0, 0.0);
	return (self);
}

void	col_free(t_color *self)
{
	free(self);
}
	/*self->rgb = vec3_new();
	if (!self->rgb)
	{
		free(self);
		return (NULL);
	}*/

	//vec3_free(self->rgb);