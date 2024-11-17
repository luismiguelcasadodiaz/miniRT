/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_getters_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:06 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/14 09:58:02 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "color.h"

double	col_get_t_1(t_color *self)
{
	return (self->t / 255);
}

double	col_get_r_1(t_color *self)
{
	return (self->rgb.e[0]);
}

double	col_get_g_1(t_color *self)
{
	return (self->rgb.e[1]);
}

double	col_get_b_1(t_color *self)
{
	return (self->rgb.e[2]);
}

/*
int	col_get_t(int color)
{
	return ((color >> 24) & 0xFF);
}

int	col_get_r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	col_get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	col_get_b(int color)
{
	return (color & 0xFF);
}
*/
