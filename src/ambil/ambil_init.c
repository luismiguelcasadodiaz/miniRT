/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambil_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:00 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/30 19:58:13 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambil.h"

t_ambil	*ambil_new(void)
{
	t_ambil	*self;

	self = (t_ambil *)malloc(sizeof(t_ambil));
	if (!self)
		return (NULL);
	self->color = col_new();
	if (!self->color)
	{
		free(self);
		self = NULL;
	}
	self->ambient = col_new();
	if (!self->ambient)
	{
		col_free(self->color);
		free(self);
		self = NULL;
	}
	return (self);
}

void	ambil_free(t_ambil *self)
{
	if (self->color)
		col_free(self->color);
	if (self->ambient)
		col_free(self->ambient);
	free(self);
}

void	ambil_init(t_ambil *self)
{
	col_init_with_1(self->color, 0.0, 0.0, 0.0);
	ambil_set_lambi(self, 0.0);
}

t_ambil	*ambil_set(double lambi, t_color *rgb255)
{
	t_ambil	*self;

	self = ambil_new();
	ambil_set_lambi(self, lambi);
	ambil_set_color(self, rgb255);
	ambil_set_ambient(self);
	return (self);
}
