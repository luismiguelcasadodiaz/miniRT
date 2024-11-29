/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:56:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/30 20:05:10 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "vec3.h"
# include "color.h"

typedef struct s_light
{
	t_vec3			*coor;
	t_color			*color;
	double			lbrig;
	struct s_light	*next;
}	t_light;

// light_init.c
t_light			*light_new(void);

void			light_init(t_light *self);
void			light_free(t_light *self);
// light_setters_one.c
t_light			*light_set(t_vec3 *coor, double lbrig);
t_light			*light_set_bonus(t_vec3 *coor, double lbrig, t_color *rgb255);
void			light_set_coord(t_light *self, t_vec3 *coor);
void			light_set_color(t_light *self, t_color *color);
void			light_set_lbrig(t_light *self, double lbrig);

// light_getters_one.c
t_vec3			*light_get_coord(t_light *self);
t_color			*light_get_color(t_light *self);
double			light_get_lbrig(t_light *self);

// light_show.c
void			light_print(t_light *self);
void			light_add(t_light **self, t_light *new);

// light_fix_lightnts.c
#endif
