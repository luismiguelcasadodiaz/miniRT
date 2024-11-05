/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:56:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/21 17:16:45 by luicasad         ###   ########.fr       */
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

typedef struct s_ray		t_ray;
typedef struct s_eleme		t_eleme;
typedef struct s_hitrecord	t_hitrecord;

typedef bool				(*t_hitfp)(t_eleme *self, t_ray *r,
	t_interval *range, t_hitrecord *rec);
/* ************************************************************************** */
/*  *next (8): pointer to next element                                        */
/*  *coor (8): sphere/culinder center or plane point or                       */
/*  *novec(8): plane or cylinder normal                                       */
/*  *color(8): element colo                                                   */
/*  *hit  (8): function to detect ray impact                                  */
/*  *u    (8): calculated from a plane's normal, defines a plane              */
/*  *v    (8): calculated form a plane's normal, defines a plane              */
/*  d     (8): double sphere diameter or cylinder diamenter                   */
/*  h     (8): double cylinder height                                         */
/*  id    (4): element type identifier                                        */
/* ************************************************************************** */
typedef struct s_eleme
{
	t_eleme			*next;
	t_vec3			*coor;
	t_vec3			*novec;
	t_color			*color;
	t_hitfp			*hit;
	t_vec3			*u;
	t_vec3			*v;
	t_vec3			*w;
	double			d;
	double			h;
	enum e_eleme	id;
}	t_eleme;


// eleme_new.c
t_eleme			*eleme_new(void);
// eleme_init.c
void			eleme_init(t_eleme *self);
void			eleme_free(t_eleme *self);
void			eleme_add(t_eleme **self, t_eleme *new);
bool			eleme_hit(t_eleme *e, t_ray *r, t_interval *i, t_hitrecord *c);
// eleme_setters_one.c
void			eleme_set_ident(t_eleme *self, enum e_eleme id);
void			eleme_set_diame(t_eleme *self, double d);
void			eleme_set_heigh(t_eleme *self, double h);
void			eleme_set_hit(t_eleme *self, t_hitfp func);
void			eleme_set_w(t_eleme *self, t_vec3 *w);
// eleme_setters_two.c
void			eleme_set_coord(t_eleme *self, t_vec3 *coor);
void			eleme_set_novec(t_eleme *self, t_vec3 *novec);
void			eleme_set_color(t_eleme *self, t_color *color);
void			eleme_set_u(t_eleme *self, t_vec3 *u);
void			eleme_set_v(t_eleme *self, t_vec3 *v);
// eleme_getters_one.c
enum e_eleme	eleme_get_ident(t_eleme *self);
double			eleme_get_diame(t_eleme *self);
double			eleme_get_heigh(t_eleme *self);
t_hitfp			*eleme_get_hit(t_eleme *self);
t_vec3			*eleme_get_w(t_eleme *self);
// eleme_getters_two.c
t_vec3			*eleme_get_coord(t_eleme *self);
t_vec3			*eleme_get_novec(t_eleme *self);
t_color			*eleme_get_color(t_eleme *self);
t_vec3			*eleme_get_u(t_eleme *self);
t_vec3			*eleme_get_v(t_eleme *self);

// eleme_show.c
void			eleme_print(t_eleme *self);

// eleme_fix_elements.c
t_eleme			*eleme_new_amb(double lambi, t_color *rgb_255);
t_eleme			*eleme_new_cam(t_vec3 *coor, t_vec3 *novec, double fview);
t_eleme			*eleme_new_lig(t_vec3 *coor, double lbrig, t_color *rgb255);
// eleme_new_objesc.c
t_eleme			*eleme_new_sph(t_vec3 *c, double d, t_color *rgb255);
t_eleme			*eleme_new_pla(t_vec3 *coor, t_vec3 *novec, t_color *rgb255);
t_eleme			*eleme_new_cyl(t_vec3 *coor, t_vec3 *novec,
					t_vec3 *dim, t_color *rgb_255);
// eleme_hittables_sph.c
bool	hit_sphere(t_eleme *slf, t_ray *ray, t_interval *ran, t_hitrecord *rec);
// eleme_hittables_pln.c
bool	hit_plane(t_eleme *self, t_ray *ray, t_interval *ran, t_hitrecord *rec);
// eleme_hittables_cyl.c
bool 	hit_cyl(t_eleme *self, t_ray *ray, t_interval *ran, t_hitrecord *rec);

#endif
