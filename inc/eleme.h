/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:56:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/16 17:39:25 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEME_H
# define ELEME_H
# include "vec3.h"
# include "color.h"

typedef struct	s_eleme
{
	unsigned char	id;
	t_vec3			*coor;
	t_vec3			*novec;
	t_color			*color;
	double			d;
	double			h;
	double			fview;
	double			lambi;
	double			lbrig;
}	t_eleme;

// eleme_init.c
t_eleme	*eleme_new();
void	eleme_init(t_eleme *self);
// eleme_setters_one.c
void	eleme_set_ident(t_eleme *self);
void	eleme_set_coord(t_eleme *self);
void	eleme_set_novec(t_eleme *self);
void	eleme_set_color(t_eleme *self);
void	eleme_set_diame(t_eleme *self);
// eleme_setters_two.c
void	eleme_set_heigh(t_eleme *self);
void	eleme_set_fview(t_eleme *self);
void	eleme_set_lambi(t_eleme *self);
void	eleme_set_lbrig(t_eleme *self);
// eleme_getters_one.c
void	eleme_get_ident(t_eleme *self);
void	eleme_get_coord(t_eleme *self);
void	eleme_get_novec(t_eleme *self);
void	eleme_get_color(t_eleme *self);
void	eleme_get_diame(t_eleme *self);
// eleme_getters_two.c
void	eleme_get_heigh(t_eleme *self);
void	eleme_get_fview(t_eleme *self);
void	eleme_get_lambi(t_eleme *self);
void	eleme_get_lbrig(t_eleme *self);

// eleme_show.c
void	eleme_show(t_eleme *self);
#endif
