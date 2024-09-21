/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 06:55:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/21 12:11:31 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "point.h"
# include "vec3.h"
# include "color.h"
# include "eleme.h"

typedef struct s_ray
{
	t_point	*orig;
	t_vec3	*dir;
}	t_ray;

t_ray	*ray_new(void);
void	ray_free(t_ray *self);
void	ray_init(t_ray *self, t_point *orig, t_vec3 *dir);
void	ray_set_orig(t_ray *self, t_point *the_point);
void	ray_set_dir(t_ray *self, t_vec3 *the_dir);
t_point	*ray_get_orig(t_ray *self);
t_vec3	*ray_get_dir(t_ray *self);
int		ray_color(t_ray *self, t_color start, t_color end, t_eleme *o);
#endif
