/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:56:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/14 19:40:50 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMER_H
# define CAMER_H
# define VIEW_PORT_H 2.0
# define FOCAL_LENGTH 1
# define HFOV_MIN 0
# define HFOV_MAX 180
# include "vec3.h"
# include "color.h"
# include "point.h"
# include "miniRT.h"
# include "eleme.h"

typedef struct s_win	t_win;
/* vport: viewport. a point with x= width & y = heigth                        */
/* cc   : camera center. a point with x= width & y = heigth                   */
/* color_start & color_end: scene background                                  */
typedef struct s_camer
{
	t_vec3		coor;
	t_vec3		novec;
	double		hfov;
	double		vfov;	
	double		aspect_ratio;
	int			image_width;
	int			image_height;
	int			samples_per_pixel;
	int			max_depth;

	t_point		lookfrom;
	t_point		lookat;
	t_vec3		vup;
	//double		defocus_angle;
	//double		focus_dist;
	//double		defocus_radius;
	t_point		vport;

	double		pixel_samples_scale;
	t_point		center;
	t_point		pixel00_loc;
	t_vec3		pd_u;
	t_vec3		pd_v;
	t_vec3		u;
	t_vec3		v;
	t_vec3		w;
	//t_vec3		defocus_disk_u;
	//t_vec3		defocus_disk_v;	
	t_vec3		vp_u;
	t_vec3		vp_v;
	t_vec3		vp_ul;
	t_color		color_start;
	t_color		color_end;
	double		focal_lenght;
	double		theta;
	double		h;
	double		viewport_height;
	double		viewport_width;
}	t_camer;

// camer_init.c
t_camer			*camer_new(void);
//void			camer_init(t_camer *self);
t_camer			*camer_set(t_vec3 *coor, t_vec3 *novec,
					double fview);
void			camer_free(t_camer *self);
// camer_setters_one.c
void			camer_s_coord(t_camer *self, t_vec3 *coor);
void			camer_s_novec(t_camer *self, t_vec3 *novec);
void			camer_s_hfov(t_camer *self, double hfov);
void			camer_s_vport(t_camer *self, double the_vp_h, t_point *size);
//void			camer_set_isize(t_camer *self, double win_w, double asp_ratio);

// camer_setters_two.c
void			camer_s_cacen(t_camer *self);
void			camer_s_vup(t_camer *self, double x, double y, double z);
void			camer_s_aspect_ratio(t_camer *self, double dato);
void			camer_s_image_width(t_camer *self, int dato);
void			camer_s_samples_per_pixel(t_camer *self, int dato);
// camer_setters_three.c
void			camer_s_max_depth(t_camer *self, int dato);
void			camer_s_vfov(t_camer *self);
//void			camer_s_vfov(t_camer *self, float hfov, t_point *size);
//void			camer_s_defocus_angle(t_camer *self, double angle);
//void			camer_s_focus_dist(t_camer *self, double dist);
void			camer_s_focal_length(t_camer *self, double dist);
void			camer_s_focal_length_ave(t_win *w);

// camer_setters_four.c
void	camer_u_hfov(t_camer *self,  double change);

// camer_getters_one.c
t_vec3			camer_g_coord(t_camer *self);
t_vec3			camer_g_novec(t_camer *self);
double			camer_g_fview(t_camer *self);

// camer_show.c
void			camer_print(t_camer *self);
//camer_calculate_one.c
void			camer_calc_vp_and_pd(t_camer *self, t_point *size);
void			camer_calc_vp_ul(t_camer *self);
void			camer_calc_pix00(t_camer *self);
void			camer_calc_background_colors(t_camer *w);
void			camer_calc_image_height(t_camer *self);

//camer_calculate_two.c
void			camer_calc_pixel_samples_scale(t_camer *self);
void			camer_calc_theta(t_camer *self);
void			camer_calc_h(t_camer *self);
void			camer_calc_viewport_height(t_camer *self);
void			camer_calc_vierport_width(t_camer *self);
//camer_calculate_thr.c
void			camer_calc_w(t_camer *self);
void			camer_calc_u(t_camer *self);
void			camer_calc_v(t_camer *self);
void			camer_calc_viewport_u(t_camer *self);
void			camer_calc_viewport_v(t_camer *self);
//camer_calculate_fou.c
void			camer_calc_pixel_delta_u(t_camer *self);
void			camer_calc_pixel_delta_v(t_camer *self);
void			camer_calc_viewport_upper_left(t_camer *self);
void			camer_calc_pixel00_loc(t_camer *self);
void			camer_calc_background_colors_ambil(t_camer *self,
					t_color *ambil);
//void			camer_calc_defocus_radius(t_camer *self);
//camer_calculate_fiv.c
//void			camer_calc_defocus_disk_u(t_camer *self);
//void			camer_calc_defocus_disk_v(t_camer *self);

#endif
