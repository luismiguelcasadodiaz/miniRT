/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_setters_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:09 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/20 20:29:20 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

void	eleme_set_heigh(t_eleme *self, double h)
{
	self->h = h;
}

void	eleme_set_fview(t_eleme *self, double fview)
{
	self->fview = fview;
}

void	eleme_set_lambi(t_eleme *self, double lambi)
{
	self->lambi = lambi;
}

void	eleme_set_lbrig(t_eleme *self, double lbrig)
{
	self->lbrig = lbrig;
}
