/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambil_setters_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:04 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/30 19:50:33 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambil.h"

void	ambil_set_color(t_ambil *self, t_color *color)
{
	col_copy_values(self->color, color);
	col_scale(self->ambient, self->color, self->lambi);
}

void	ambil_set_lambi(t_ambil *self, double lambi)
{
	self->lambi = lambi;
	col_scale(self->ambient, self->color, self->lambi);
}

void	ambil_set_ambient(t_ambil *self)
{
	col_scale(self->ambient, self->color, self->lambi);
}
