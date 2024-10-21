/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:39:31 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/21 23:39:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"
#include "ray.h"
#include "interval.h"
#include "hitrecord.h"
#include <stdbool.h>


bool	eleme_hit(t_eleme *e, t_ray *r, t_interval *i, t_hitrecord *c)
{
    t_hitrecord *tem_rec;
    bool        hit_anything;
    t_interval  *interval_aux;
    t_eleme     *aux;

    tem_rec = hitrecord_new();
    interval_aux = interval_new();
    interval_init(interval_aux, interval_get_min(i), interval_get_max(i));
    hit_anything = false;
    aux = e;
    while (aux)
    {
        if ((*e->hit)(e, r, interval_aux, tem_rec))
        {
            hit_anything = true;
            interval_init(interval_aux, interval_get_min(i), tem_rec->t);
            hitrecord_copy(c, tem_rec);  
        }
        aux = aux->next;
    }
    hitrecord_free(tem_rec);
    interval_free(interval_aux);
    return (hit_anything);
}