/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:47:24 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/08 00:15:32 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include "vec3.h"

//typedef struct s_point
//{
//	double	x;
//	double	y;
//	double	z;
//}	t_point;
typedef t_vec3	t_point;

t_point	*point_new(void);
void	point_free(t_point *self);
void	point_init(t_point *self, double x, double y, double z);
void	point_set_x(t_point *self, double the_x);
void	point_set_y(t_point *self, double the_y);
void	point_set_x(t_point *self, double the_z);
double	point_get_x(t_point *self);
double	point_get_y(t_point *self);
double	point_get_z(t_point *self);
void	point_print(t_point *self);
#endif
