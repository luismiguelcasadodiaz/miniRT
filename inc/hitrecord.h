/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitrecord.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:18:27 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/22 23:38:10 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITRECORD_H
# define HITRECORD_H
# include "point.h"
# include "ray.h"
# include "vec3.h"
# include "eleme.h"

typedef struct s_ray	t_ray;
typedef struct s_eleme	t_eleme;

/* ************************************************************************** */
/*        *p : Impact point                                                   */
/*   *normal : Surface normal in the impact point                             */
/*         t : Value t in traced ray that impact the object                   */
/*front_face : flag front or rear face                                        */
/*  *hit_obj : Hitted object                                                  */
/*  *mat_ptr : Hitted objetct's material                                      */
/* ************************************************************************** */
typedef struct s_hitrecord
{
	t_point	*p;
	t_vec3	*normal;
	double	t;
	int		front_face;
	t_eleme	*hit_obj;
	//t_mat	*mat;
}	t_hitrecord;

// hitrecord_init.c
t_hitrecord	*hitrecord_new(void);
void		hitrecord_free(t_hitrecord *self);
void		hitrecord_init(t_hitrecord *self);
void		hitrecord_copy(t_hitrecord *dest, t_hitrecord *ori);
// hitrecord_getters.c
t_point		*hitrecord_get_point(t_hitrecord *self);
t_vec3		*hitrecord_get_normal(t_hitrecord *self);
double		hitrecord_get_t(t_hitrecord *self);
int			hitrecord_get_front_face(t_hitrecord *self);
void		*hitrecord_get_hit_obj(t_hitrecord *self);
// hitrecord_setters.c
void		hitrecord_set_point(t_hitrecord *self, t_point *the_p);
void		hitrecord_set_normal(t_hitrecord *self, t_vec3 *the_normal);
void		hitrecord_set_t(t_hitrecord *self, double the_t);
void		hitrecord_set_front_face(t_hitrecord *self, int the_front_face);
void		hitrecord_set_hit_obj(t_hitrecord *self, void *the_hit_obj);
// hitrecord_methods.c
void		hitrecord_face_normal(t_hitrecord *self, t_ray *r, t_vec3 *norm);
#endif
