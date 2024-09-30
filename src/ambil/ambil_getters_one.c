/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambil_getters_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:32:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/30 19:52:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambil.h"

t_color	*ambil_get_color(t_ambil *self)
{
	return (self->color);
}

double	ambil_get_lambi(t_ambil *self)
{
	return (self->lambi);
}
