/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:47:24 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/30 23:28:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define MLX_ERROR 1
# define INITIAL_ZOOM 1
# define ZOOM_FACTOR 1.05
# define MAX_ITERATIONS 2
# define WINDOW_W 1000

# define ASPECT_RATIO_W 16.0
# define ASPECT_RATIO_H 9.0

# define BLACK 0x00000000
# define RED   0x00FF0000
# define GREEN 0x0000FF00
# define BLUE  0x000000FF
# define WHITE 0x00FFFFFF

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17
/*# include "ft_complex.h"*/
# include <stdlib.h>
# include "point.h"
# include "vec3.h"
# include "color.h"
# include "ray.h"
# include "eleme.h"
# include "camer.h"
# include "ambil.h"
# include "light.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*  real : real axis width. From -2 to 2. starts with 2 * COMPLEX_REAL_MAX    */
/*  imag : imag axis height. From -i to i. starts with 2 * COMPLEX_IMAG_MAX   */
/*  r_x  :ratio horizontal real_width / horizontal _width                     */
/*  r_y  :ratio horizontal imag_width / vertical _width                       */
/*                                                                            */
/* ************************************************************************** */
typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_point		*size;
//	t_point		lu;
//	t_point		rd;
//	int			x_0;
//	int			y_0;
//	float		real;
//	float		imag;
//	float		r_x;
//	float		r_y;
/*	t_complex	z;*/
}	t_img;

/* ************************************************************************** */
/* size : for window. a point with x= width & y = heigth                      */
/* lu   : left upper coordinate                                               */
/* rd   : right down coordinate                                               */
/* ************************************************************************** */

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	char		*title;
	t_point		*size;
	t_point		*lu;
	t_point		*rd;
	t_vec3		*ray_direction;
	t_ambil		*ambient;
	t_camer		*camera;
	t_light		*light;	
	t_eleme		*eleme;
}				t_win;

t_win	win_init(char *title);
void	win_free(t_win w);
int		win_h_key_down(int keysym, t_win *data);
int		win_h_key_up(int keysym, t_win *data);
int		win_h_mouse_down(int button, int x, int y, t_win *data);
int		win_h_mouse_up(int button, int x, int y, t_win *data);
int		win_h_mouse_move(int x, int y, t_win *data);
int		win_h_not_event(t_win *data);
int		win_h_expose(t_win *data);
int		win_h_destroy(t_win *data);
void	win_pixel_put(t_win w, int x, int y, int color);
void	win_world_create(t_eleme **eleme);
void	draw_fractal(t_win w);
void	draw_square_2(t_win w, t_point upper_left, t_point lower_right);
void	draw_image1(t_win w);
void	draw_image2(t_win *w);
void	draw_image3(t_win *w);
void	draw_image4(t_win *w);
void	show_usage(void);
void	show_data(t_win w);
void	read_file(char *filename, char **errmsg);
void	treat_ambient(char **chunks, char **errmsg);
void	treat_camera(char **chunks, char **errmsg);
void	treat_light(char **chunks, char **errmsg);
void	treat_sphere(char **chunks, char **errmsg);
void	treat_plane(char **chunks, char **errmsg);
void	treat_cylin(char **chunks, char **errmsg);
void	treat_one_letter_command(char **chunks, char **errmsg);
void	treat_two_letter_command(char **chunks, char **errmsg);
void	error_bad_letter_command(char **chunks, char **errmsg);

