/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleme_hitables_cyl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:40:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 12:18:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"
static double	calc_discriminant(t_eleme *self, t_ray *ray, double *half_b)
{
	double 	c;
	double 	a;
	double 	axis_dot_d;
    double 	axis_dot_oc;
	t_vec3	*oc;
	t_vec3	*d_proj;
	t_vec3	*oc_proj;

	oc = vec3_new();
    vec3_sub(oc, ray->orig, self->coor); // Vector del centro del cilindro al origen del rayo
    axis_dot_d = vec3_dot(self->novec, ray->dir);// Variables para el impacto en el cuerpo del cilindro
    axis_dot_oc = vec3_dot(self->novec, oc);
    vec3_scale(&d_proj, self->novec, axis_dot_d); // Proyección de la dirección del rayo en el eje
    vec3_sub(&d_proj, ray->dir, &d_proj);
    vec3_scale(&oc_proj, self->novec, axis_dot_oc); // Proyección de oc en el eje
    vec3_sub(&oc_proj, &oc, &oc_proj);
    a = vec3_length_squared(&d_proj);
    c = vec3_length_squared(&oc_proj) - ((self->d / 2) * (self->d / 2));
	*half_b = vec3_dot(&d_proj, &oc_proj);
	return (*half_b * *half_b - a * c);
}

bool hit_cil(t_eleme *self, t_ray *ray, t_interval *ran, t_hitrecord *rec)
{



	t_vec3 	top_center;
	t_vec3	bottom_center;
    t_vec3 	half_height;
	t_vec3	center_to_hit;
	t_vec3	hit_point;
    double 	half_b;
	double	discriminant;
	t_vec3  hit_point;
	double height_proj;
	t_vec3 outward_normal;
    t_vec3 scale_proj;
	double root;
	double sqrt_disc;
	t_vec3 from_center;
	t_vec3 p_top;
	t_vec3 p_bottom;
	double t_top;
	double t_bottom;
	double denom;


    discriminant = calc_discriminant( &half_b)
    if (discriminant >= 0) {
        sqrt_disc = sqrt(discriminant);
        root = (-half_b - sqrt_disc) / a;
        if (!interval_contains(ray_t, root)) {
            root = (-half_b + sqrt_disc) / a;
            if (!interval_contains(ray_t, root)) return false;
        }
        hit_point = ray_at(r, root);
        vec3_sub(&center_to_hit, &hit_point, &cil->center);
        height_proj = vec3_dot(&center_to_hit, &cil->axis);
        if (height_proj >= -cil->height / 2 && height_proj <= cil->height / 2) {
            rec->t = root;
            rec->p = hit_point;
            rec->mat_ptr = cil->mat;
            rec->hit_obj = (void*)cil;
            vec3_scale(&scale_proj, &cil->axis, height_proj);
            vec3_sub(&outward_normal, &center_to_hit, &scale_proj);
            vec3_unit_vector(&rec->normal, &outward_normal);
            rec->front_face = vec3_dot(&r->dir, &rec->normal) < 0;
            if (!rec->front_face)
                vec3_negate(&rec->normal, &rec->normal);
            return true;
        }
    }
    // Calcular el impacto en las tapas

    vec3_scale(&half_height, &cil->axis, cil->height / 2);
    vec3_add(&bottom_center, &cil->center, &half_height); // Centro de la tapa inferior
    vec3_sub(&top_center, &cil->center, &half_height); // Centro de la tapa superior


    // Verificar intersección con la tapa inferior
    denom = vec3_dot(&cil->axis, &r->dir);
    if (fabs(denom) > 1e-8) 
	{
        t_bottom = (vec3_dot(&cil->axis, &bottom_center) - vec3_dot(&cil->axis, &r->orig)) / denom;
        if (interval_contains(ray_t, t_bottom)) {
            p_bottom = ray_at(r, t_bottom);
            vec3_sub(&from_center, &p_bottom, &bottom_center);
            if (vec3_length_squared(&from_center) <= cil->radius * cil->radius) {
                rec->t = t_bottom;
                rec->p = p_bottom;
                rec->mat_ptr = cil->mat;
                rec->hit_obj = (void*)cil;
                rec->normal = cil->axis;
                rec->front_face = (vec3_dot(&r->dir, &rec->normal) < 0);
                if (!rec->front_face)
                    vec3_negate(&rec->normal, &rec->normal);
                return true;
            }
        }

        // Intersección con el plano de la tapa superior
        //double t_top = vec3_dot(&cil->axis, &top_center) - vec3_dot(&cil->axis, &r->orig) / denom;
        t_top = (vec3_dot(&cil->axis, &top_center) - vec3_dot(&cil->axis, &r->orig)) / denom;
        if (interval_contains(ray_t, t_top)) {
            p_top = ray_at(r, t_top);
            vec3_sub(&from_center, &p_top, &top_center);
            if (vec3_length_squared(&from_center) <= cil->radius * cil->radius) {
                rec->t = t_top;
                rec->p = p_top;
                rec->mat_ptr = cil->mat;
                rec->hit_obj = (void*)cil;
                rec->normal = cil->axis;//normal alineada con el eje
                rec->front_face = (vec3_dot(&r->dir, &rec->normal) < 0);
                if (!rec->front_face)
                    vec3_negate(&rec->normal, &rec->normal);
                return true;
            }
        }
    }
    return false;  // Si no hay impacto en el cuerpo ni en las tapas, no hay intersección
}

// t_vec3 *d holds diameter in x, and height in y. 42 norm restrictions !!!!
t_eleme	*eleme_new_cyl(t_vec3 *coor, t_vec3 *novec, t_vec3 *d, t_color *rgb255)
{
	t_eleme	*self;

	self = eleme_new();
	eleme_set_ident(self, CYLINDER);
	eleme_set_coord(self, coor);
	eleme_set_novec(self, novec);
	eleme_set_color(self, rgb255);
	eleme_set_diame(self, vec3_get_x(d));
	eleme_set_heigh(self, vec3_get_y(d));
	return (self);
}
