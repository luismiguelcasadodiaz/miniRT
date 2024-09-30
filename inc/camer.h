/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:56:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/30 19:27:40 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMER_H
# define CAMER_H
# include "vec3.h"
# include "color.h"

typedef struct s_camer
{
	t_vec3			*coor;
	t_vec3			*novec;
	double			fview;
}	t_camer;

// camer_init.c
t_camer			*camer_new(void);
void			camer_init(t_camer *self);
t_camer			*camer_set(t_vec3 *coor, t_vec3 *novec, double fview);
void			camer_free(t_camer *self);
// camer_setters_one.c
void			camer_set_coord(t_camer *self, t_vec3 *coor);
void			camer_set_novec(t_camer *self, t_vec3 *novec);
void			camer_set_fview(t_camer *self, double fview);
// camer_getters_one.c
t_vec3			*camer_get_coord(t_camer *self);
t_vec3			*camer_get_novec(t_camer *self);
double			camer_get_fview(t_camer *self);

// camer_show.c
void			camer_print(t_camer *self);

#endif
