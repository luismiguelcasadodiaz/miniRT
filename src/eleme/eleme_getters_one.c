/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_getters_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:32:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/01 19:22:30 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

enum e_eleme	eleme_get_ident(t_eleme *self)
{
	return (self->id);
}

double	eleme_get_diame(t_eleme *self)
{
	return (self->d);
}

double	eleme_get_heigh(t_eleme *self)
{
	return (self->h);
}
