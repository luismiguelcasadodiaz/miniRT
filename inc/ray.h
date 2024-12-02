/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 06:55:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/02 11:57:30 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "point.h"
# include "vec3.h"
# include "color.h"
# include "eleme.h"
# include "miniRT.h"

typedef struct s_eleme		t_eleme;
typedef struct s_win		t_win;
typedef struct s_hit_args	t_hit_args;

typedef struct s_ray
{
	t_point	*orig;
	t_vec3	*dir;
	double	t_max;
}	t_ray;

t_ray	*ray_new(void);
void	ray_free(t_ray *self);
void	ray_init(t_ray *self, t_point *orig, t_vec3 *dir);
void	ray_set_orig(t_ray *self, t_point *the_point);
void	ray_set_dir(t_ray *self, t_vec3 *the_dir);
t_point	*ray_get_orig(t_ray *self);
t_vec3	*ray_get_dir(t_ray *self);
t_color	ray_color(t_ray *self, t_win *w);
t_point	*ray_at(t_ray *self, double t);
void	ray_shadow(t_hit_args *data, t_win *w);
#endif
