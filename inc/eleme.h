/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:56:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/02 12:01:48 by luicasad         ###   ########.fr       */
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
	CYLINDER,
	CONE
};

enum e_fix
{
	AMBIENT,
	CAMERA,
	LIGHT
};

typedef struct s_ray		t_ray;
typedef struct s_eleme		t_eleme;
typedef struct s_hitrecord	t_hitrecord;
typedef struct s_interval	t_interval;

typedef struct s_hit_args
{
	t_eleme		*self;
	t_ray		*ray;
	t_interval	*ran;
	t_hitrecord	*rec;
	t_color		*shadow_col;
}	t_hit_args;

//typedef bool				(*t_hitfp)(t_eleme *self, t_ray *r,
//	t_interval *range, t_hitrecord *rec);
typedef bool				(*t_hitfp)(t_hit_args *data);

/*define signature for a three argument function pointer*/
typedef void				(*t_vec3fp)(t_vec3 *result, const t_vec3 *u,
										const t_vec3 *v);

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
bool			eleme_hit(t_hit_args *data);
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
t_vec3			eleme_average_coor(t_eleme *self);
// eleme_new_objesc.c
t_eleme			*eleme_new_sph(t_vec3 *c, double d, t_color *rgb255);
t_eleme			*eleme_new_pla(t_vec3 *coor, t_vec3 *novec, t_color *rgb255);
t_eleme			*eleme_new_cyl(t_vec3 *coor, t_vec3 *novec,
					t_vec3 *dim, t_color *rgb_255);
// eleme_hittables_sph.c
bool			hit_sphere(t_hit_args *data);
// eleme_hittables_pln.c
bool			hit_plane(t_hit_args *data);
// eleme_hittables_cyl_one.c
bool			hit_cyl(t_hit_args *data);
// eleme_hittables_cyl_one.c
int				calc_body(t_hit_args *dat, double dis, double hlf_b, double a);

// hit_args_init.c

t_hit_args		*hit_args_new_l(void);
void			hit_args_free_l(t_hit_args *self);
t_hit_args		*hit_args_new_s(void);
void			hit_args_free_s(t_hit_args *self);
#endif
