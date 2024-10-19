/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:56:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 17:56:30 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEME_H
# define ELEME_H
# include "vec3.h"
# include "color.h"
# include "ray.h"
# include "hitrecord.h"
# include "interval.h"
# include <stdbool.h>



enum e_eleme
{
	NOELEM,
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct s_ray	t_ray;
typedef struct s_eleme	t_eleme;
typedef struct s_hitrecord t_hitrecord;

typedef bool			(*t_hitfp)(t_eleme *self, t_ray *r,
	t_interval *range, t_hitrecord *rec);

typedef struct s_eleme
{
	enum e_eleme	id;
	t_vec3			*coor;
	t_vec3			*novec;
	t_color			*color;
	double			d;
	double			h;
	t_hitfp			*hit;
}	t_eleme;

// eleme_init.c
t_eleme			*eleme_new(void);
void			eleme_init(t_eleme *self);
void			eleme_free(t_eleme *self);
// eleme_setters_one.c
void			eleme_set_ident(t_eleme *self, enum e_eleme id);
void			eleme_set_diame(t_eleme *self, double d);
void			eleme_set_heigh(t_eleme *self, double h);
void			eleme_set_hit(t_eleme *self, t_hitfp func);
// eleme_setters_two.c
void			eleme_set_coord(t_eleme *self, t_vec3 *coor);
void			eleme_set_novec(t_eleme *self, t_vec3 *novec);
void			eleme_set_color(t_eleme *self, t_color *color);
// eleme_getters_one.c
enum e_eleme	eleme_get_ident(t_eleme *self);
double			eleme_get_diame(t_eleme *self);
double			eleme_get_heigh(t_eleme *self);
t_hitfp			*eleme_get_hit(t_eleme *self);
// eleme_getters_two.c
t_vec3			*eleme_get_coord(t_eleme *self);
t_vec3			*eleme_get_novec(t_eleme *self);
t_color			*eleme_get_color(t_eleme *self);

// eleme_show.c
void			eleme_print(t_eleme *self);

// eleme_fix_elements.c
t_eleme			*eleme_new_amb(double lambi, t_color *rgb_255);
t_eleme			*eleme_new_cam(t_vec3 *coor, t_vec3 *novec, double fview);
t_eleme			*eleme_new_lig(t_vec3 *coor, double lbrig, t_color *rgb255);
// eleme_hitables.c
t_eleme			*eleme_new_sph(t_vec3 *c, double d, t_color *rgb255);
t_eleme			*eleme_new_pla(t_vec3 *coor, t_vec3 *novec, t_color *rgb255);
t_eleme			*eleme_new_cyl(t_vec3 *coor, t_vec3 *novec,
					t_vec3 *dim, t_color *rgb_255);
#endif
