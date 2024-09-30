/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambil.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:56:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/30 19:59:27 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIL_H
# define AMBIL_H
# include "vec3.h"
# include "color.h"

typedef struct s_ambil
{
	t_color			*color;
	double			lambi;
}	t_ambil;

// ambil_init.c
t_ambil			*ambil_new(void);
t_ambil			*ambil_set(double lambi, t_color *rgb_255);
void			ambil_init(t_ambil *self);
void			ambil_free(t_ambil *self);
// ambil_setters_one.c
void			ambil_set_color(t_ambil *self, t_color *color);
void			ambil_set_lambi(t_ambil *self, double lambi);
// ambil_getters_one.c
t_color			*ambil_get_color(t_ambil *self);
double			ambil_get_lambi(t_ambil *self);

// ambil_show.c
void			ambil_print(t_ambil *self);

#endif
