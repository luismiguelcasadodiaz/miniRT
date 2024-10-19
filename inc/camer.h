/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:56:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 17:57:50 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMER_H
# define CAMER_H
# define VIEW_PORT_H 2.0
# define FOCAL_LENGTH 1
# include "vec3.h"
# include "color.h"
# include "point.h"

/* vport: viewport. a point with x= width & y = heigth                        */
/* cc   : camera center. a point with x= width & y = heigth                   */
/* color_start & color_end: scene background                                  */
typedef struct s_camer
{
	t_vec3		*coor;
	t_vec3		*novec;
	double		fview;
	//t_point		*size;
	t_point		*vport;
	t_point		*cacen;
	t_vec3		*vp_x;
	t_vec3		*vp_y;
	t_vec3		*pd_x;
	t_vec3		*pd_y;
	t_vec3		*vp_ul;
	t_vec3		*pixel00;
	t_color		*color_start;
	t_color		*color_end;
}	t_camer;

// camer_init.c
t_camer			*camer_new(void);
//void			camer_init(t_camer *self);
t_camer			*camer_set(t_vec3 *coor, t_vec3 *novec,
					double fview, t_point *size);
void			camer_free(t_camer *self);
// camer_setters_one.c
void			camer_set_coord(t_camer *self, t_vec3 *coor);
void			camer_set_novec(t_camer *self, t_vec3 *novec);
void			camer_set_fview(t_camer *self, double fview);
void			camer_set_vport(t_camer *self, double the_vp_h, t_point *size);
//void			camer_set_isize(t_camer *self, double win_w, double asp_ratio);
void			camer_set_cacen(t_camer *self);
// camer_getters_one.c
t_vec3			*camer_get_coord(t_camer *self);
t_vec3			*camer_get_novec(t_camer *self);
double			camer_get_fview(t_camer *self);

// camer_show.c
void			camer_print(t_camer *self);
void			camer_calculate_vp_and_pd(t_camer *w, t_point *size);
void			camer_calculate_vp_ul(t_camer *w);
void			camer_calculate_pix00(t_camer *w);
void			camer_calculate_background_colors(t_camer *w);

#endif
