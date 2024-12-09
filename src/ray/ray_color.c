/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:11:26 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/13 18:09:03 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "eleme.h"
#include "hitrecord.h"
#include "miniRT.h"
#include <math.h>

static	t_vec3	*get_normal(t_ray *self, double t)
{
	t_vec3	*vec3_0_0_minus1;
	t_vec3	*ray_at_t;
	t_vec3	*normal;

	vec3_0_0_minus1 = vec3_new();
	vec3_init_values(vec3_0_0_minus1, 0, 0, -1);
	ray_at_t = ray_at(self, t);
	vec3_sub(ray_at_t, ray_at_t, vec3_0_0_minus1);
	normal = vec3_new();
	vec3_unit_vector(normal, ray_at_t);
	vec3_free(ray_at_t);
	vec3_free(vec3_0_0_minus1);
	return (normal);
}

// Genera un número aleatorio en el intervalo [0, 1)
double random_double() {
    // Retorna un número aleatorio en el intervalo [0,1).
    return rand() / (RAND_MAX + 1.0);
}

// Genera un número aleatorio en el intervalo [min, max)
double random_double_range(double min, double max) {
    // Retorna un número aleatorio en el intervalo [min, max).
    return min + (max - min) * random_double();
}

t_vec3 vec3_random_range(double min, double max) {
    t_vec3 result;
    result.e[0] = random_double_range(min, max);
    result.e[1] = random_double_range(min, max);
    result.e[2] = random_double_range(min, max);
    return result;
}
// Implementación de vec3_near_zero
bool vec3_near_zero(const t_vec3* v) {
    // Devuelve verdadero si el vector está cerca de cero en todas las dimensiones.
    double s = 1e-8;
    return (fabs(v->e[0]) < s) && (fabs(v->e[1]) < s) && (fabs(v->e[2]) < s);
}
t_vec3 vec3_random_in_unit_sphere() {
    t_vec3 p;
    p = vec3_random_range(-1, 1);  // Generar primer vector aleatorio

    while (vec3_length_squared(&p) >= 1) {
        p = vec3_random_range(-1, 1);  // Seguir generando hasta que esté dentro de la esfera unitaria
    }

    return p;
}

t_vec3 vec3_random_unit_vector() {
    t_vec3 random_vector = vec3_random_in_unit_sphere();
    t_vec3 result;
    vec3_unit_vector(&result, &random_vector);
    return result;
}

bool lambertian_scatter(t_color *base_color, const t_ray *r_in, const t_hitrecord *rec, t_color *attenuation, t_ray *scattered) {
    (void)r_in; // No utilizamos r_in aquí directamente

    // Dirección de dispersión aleatoria
    t_vec3 scatter_direction, random_direction;
    //random_direction = vec3_random_unit_vector(); // Vector aleatorio
	random_direction = vec3_random_in_unit_sphere();
	// vec3_random(&random_direction, -1.0, +1.0);
	// vec3_unit_vector(&random_direction, &random_direction);

    vec3_add(&scatter_direction, rec->normal, &random_direction);

    // Manejar direcciones degeneradas
    if (vec3_near_zero(&scatter_direction)) {
        scatter_direction = *rec->normal;
    }

    // Inicializar el rayo dispersado
    ray_init(scattered, rec->p, &scatter_direction);

    // Aplicar color del material (usamos base_color para simular albedo)
    //*attenuation = *base_color;
    col_copy_values(attenuation,base_color);
    return true;
}

t_color color_multiply(const t_color* c1, const t_color* c2) {
    t_color result;
    result.rgb.e[0] = c1->rgb.e[0] * c2->rgb.e[0];
    result.rgb.e[1] = c1->rgb.e[1] * c2->rgb.e[1];
    result.rgb.e[2] = c1->rgb.e[2] * c2->rgb.e[2];
    return result;
}

t_color	ray_color(t_ray	*self, t_win *w, int depth)
{
	if (depth <= 0)
	{
        // Sin más rebotes, retorna negro o un color base
        return (t_color){ .rgb = { 0.0, 0.0, 0.0 }, .mlx_color = 0 };
    }

	t_vec3		*normal;
	t_color		normalized_color;
	t_hit_args	*data;

	data = hit_args_new_l();
	int_init(data->ran, 0, __DBL_MAX__);
	data->self = w->eleme;
	data->ray = self;
	if (eleme_hit(data))
	{
		normal = get_normal(data->ray, hitrecord_get_t(data->rec));
		col_init_with_1(&normalized_color,
			vec3_get_x(&data->rec->hit_obj->color->rgb),
			vec3_get_y(&data->rec->hit_obj->color->rgb),
			vec3_get_z(&data->rec->hit_obj->color->rgb));
		// Agregar dispersión lambertiana
        t_ray *scattered;
		scattered = ray_new();
        t_color attenuation;
        if (lambertian_scatter(&normalized_color, self, data->rec, &attenuation, scattered)) {
            // Calcular el color del rayo dispersado recursivamente
            //data->ray = scattered;
			t_color scattered_color = ray_color(scattered, w, depth - 1);

            // Aplicar la atenuación (albedo)
            scattered_color = color_multiply(&scattered_color, &attenuation);

            // Sumar el color dispersado al color base
            col_add(&normalized_color, &normalized_color, &scattered_color);
            ray_shadow(data, w);
		    col_add(&normalized_color, &normalized_color, data->shadow_col);
		    hit_args_free_l(data);
	        return (normalized_color);
        }
        else{
            // data->ray = self;
            ray_shadow(data, w);
            col_add(&normalized_color, &normalized_color, data->shadow_col);
            hit_args_free_l(data);
	        return (normalized_color);
		//ray_free(scattered);
        }
		vec3_free(normal);
	}
	else
		normalized_color = col_lerp(w, self->dir);
	hit_args_free_l(data);
	return (normalized_color);
}

		// col_init_with_1(&normalized_color, 0.5 * (1 + vec3_get_x(normal)),
		// 	0.5 * (1 + vec3_get_y(normal)), 0.5 * (1 + vec3_get_z(normal)));

		//mlx_color = col_get_mlx_color(&normalized_color);
		//mlx_color = col_get_mlx_color(data->rec->hit_obj->color);
