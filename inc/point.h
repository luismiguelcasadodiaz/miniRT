/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:47:24 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/13 08:11:36 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

t_point	*point_new(void);
void	point_free(t_point *self);
void	point_init(t_point *self, int x, int y, int z);
void	point_set_x(t_point *self, int the_x);
void	point_set_y(t_point *self, int the_y);
void	point_set_x(t_point *self, int the_z);
int		point_get_x(t_point *self);
int		point_get_y(t_point *self);
int		point_get_z(t_point *self);
#endif
