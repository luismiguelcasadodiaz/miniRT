/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:00:58 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/21 18:38:47 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

//	int	m_x;
//	int	m_y;
//	m_x = w->img.size.x / 2;
//	m_y = w->img.size.y / 2;
//	w->img.lu = point_set(-m_x, m_y);
//	w->img.rd = point_set(m_x, -m_y);
//	w->img.x_0 = 0;
//	w->img.y_0 = 0;
//	w->img.real = 2;
//	w->img.imag = 2;
//	w->img.r_x = w->img.real / w->img.size.x;
//	w->img.r_y = w->img.imag / w->img.size.y;

static void	set_init_values_img(t_win *w)
{
	ft_bzero(&w->img, sizeof(t_img));
	w->img.img_ptr = NULL;
	w->img.addr = NULL;
	w->img.bits_per_pixel = 0;
	w->img.line_length = 0;
	w->img.endian = 0;
	w->img.size = w->size;
}

/* ************************************************************************** */
/* height is calculated from width and aspect ratio. Forc to be at least 1    */
/* View_port_w (x) derived from VIEW_PORT_H times image size aspect ratio     */
/* Camera center set to (0, 0, 0)                                             */
/* ************************************************************************** */
static void	set_init_values_win(t_win *w, char *title)
{
	int		height;
	t_vec3	*coor;

	height = (int)(WINDOW_W * ASPECT_RATIO_H / ASPECT_RATIO_W);
	if (height < 1.0)
		height = 1;
	ft_bzero(w, sizeof(t_win));
	w->title = title;
	w->size = point_new();
	if (w->size)
		point_init(w->size, WINDOW_W, height, 0);
	w->lu = point_new();
	point_init(w->lu, 0, 0, 0);
	w->rd = point_new();
	point_init(w->rd, WINDOW_W, height, 0);
	set_init_values_img(w);
	w->ray_direction = vec3_new();
	w->ambient = ambil_new();
	coor = vec3_new();
	vec3_init_values(coor, 0, 0, 0);
	w->camera = camer_set(coor, coor, 0.0, w->size);
	camer_print(w->camera);
	vec3_free(coor);
	w->light = light_new();
	w->eleme = NULL;
	win_world_create(w->eleme);
}

t_win	win_init(char *title)
{
	t_win	w;

	set_init_values_win(&w, title);
	w.mlx_ptr = mlx_init();
	if (w.mlx_ptr == NULL)
		exit (-1);
	w.win_ptr = mlx_new_window(w.mlx_ptr,
			(int)w.size->e[0], (int)w.size->e[1], w.title);
	if (w.win_ptr == NULL)
	{
		free(w.mlx_ptr);
		exit (-1);
	}
	w.img.img_ptr = mlx_new_image(w.mlx_ptr,
			(int)w.img.size->e[0], (int)w.img.size->e[1]);
	if (w.img.img_ptr == NULL)
	{
		free(w.win_ptr);
		free(w.mlx_ptr);
		exit (-1);
	}
	w.img.addr = mlx_get_data_addr(w.img.img_ptr, &w.img.bits_per_pixel,
			&w.img.line_length, &w.img.endian);
	return (w);
}

void	win_free(t_win w)
{
	point_free(w.size);
	point_free(w.lu);
	point_free(w.rd);
	ambil_free(w.ambient);
	camer_free(w.camera);
	light_free(w.light);
	eleme_free(w.eleme);
}
