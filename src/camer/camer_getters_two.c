/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_getters_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:32:53 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/20 20:26:05 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

double	eleme_get_heigh(t_eleme *self)
{
	return (self->h);
}

double	eleme_get_fview(t_eleme *self)
{
	return (self->fview);
}

double	eleme_get_lambi(t_eleme *self)
{
	return (self->lambi);
}

double	eleme_get_lbrig(t_eleme *self)
{
	return (self->lbrig);
}
