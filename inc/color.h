/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:33:42 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/20 20:41:14 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vec3.h"
# include <stdlib.h>
# 

/* ************************************************************************** */
/* rgb is made of doubles. keeps colors in range 0 .. 1                       */
/* mlx_color(4 bytes). Uses 1 per color (t, r, g, b) in range 0 .. 255        */
/* ************************************************************************** */
typedef struct s_color
{
	t_vec3	rgb;
	int		t;
	int		mlx_color;
}	t_color;

// memory allocation and release (col_create.c)
t_color	*col_new(void);
void	col_free(t_color *self);

// color initialization routines
void	col_init_with_255(t_color *self, int r, int g, int b);
void	col_init_with_1(t_color *self, double r, double g, double b);
void	col_create_mlx_color(t_color *self);
//int		col_create_mlx_color_with_double(t_vec3 *the_rgb, double the_t);
//int		col_create_mlx_color_with_int(int t, int r, int g, int b);

//getters returnnig color in range 0 .. 255 (col_getters_255.c)
int		col_get_t_255(t_color *self);
int		col_get_r_255(t_color *self);
int		col_get_g_255(t_color *self);
int		col_get_b_255(t_color *self);
int		col_get_mlx_color(t_color *self);
//getters returnnig color in range 0 .. 1 (col_getters_1.c)
double	col_get_t_1(t_color *self);
double	col_get_r_1(t_color *self);
double	col_get_g_1(t_color *self);
double	col_get_b_1(t_color *self);
//setters of values in range 0 .. 255 (col_setters_255.c)
void	col_set_t_255(t_color *self, int value);
void	col_set_r_255(t_color *self, int value);
void	col_set_g_255(t_color *self, int value);
void	col_set_b_255(t_color *self, int value);
//setters of values in range 0 .. 1 (col_setters_1.c)
void	col_set_t_1(t_color *self, double value);
void	col_set_r_1(t_color *self, double value);
void	col_set_g_1(t_color *self, double value);
void	col_set_b_1(t_color *self, double value);

int		col_in_range(t_color *self);
int		col_lerp(t_color *start, t_color *end, t_vec3 *direction);
void	col_print(t_color *self);
void	col_copy_values(t_color *dest, t_color *orig);
#endif
