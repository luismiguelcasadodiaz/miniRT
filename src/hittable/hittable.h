/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:34:44 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 11:55:14 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

# include "ray.h"
# include "hitrecord.h"
# include "interval.h"

/* ************************************************************************** */
/* (*hit) : Pointer to the funciton that calculates id the ray hits an element*/
/* ************************************************************************** */
typedef struct s_hittable
{
	bool (*hit)((t_hittable *) h, (t_ray *) r, t_interval range,
		(t_hitrecord *) rec);
}	t_hittable;

void	hittable_new(void);
void	hittable_init(t_hittalbe *self);
// hittable_setters.c
void	hittable_set_hit(t_hittable *self, (*)f);
// hittable_getters.c
bool (*)hittable_get_hit((t_hittable *) self);
#endif
