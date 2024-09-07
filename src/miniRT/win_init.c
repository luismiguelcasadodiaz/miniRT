/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:49:57 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/06 13:39:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static void	set_init_values_img(t_win *w)
{
	int	m_x;
	int	m_y;

	ft_bzero(&w->img, sizeof(t_img));
	w->img.img_ptr = NULL;
	w->img.addr = NULL;
	w->img.bits_per_pixel = 0;
	w->img.line_length = 0;
	w->img.endian = 0;
	w->img.size = w->size;
	m_x = w->img.size.x / 2;
	m_y = w->img.size.y / 2;
	w->img.lu = point_set(-m_x, m_y);
	w->img.rd = point_set(m_x, -m_y);
	w->img.x_0 = 0;
	w->img.y_0 = 0;
	w->img.real = 2;
	w->img.imag = 2;
	w->img.r_x = w->img.real / w->img.size.x;
	w->img.r_y = w->img.imag / w->img.size.y;
}

static void	set_init_values_win(t_win *w, char *title)
{
	ft_bzero(w, sizeof(t_win));
	w->title = title;
	w->size = point_set(WINDOW_W, WINDOW_H);
	w->lu = point_set(0, 0);
	w->rd = point_set(WINDOW_W, WINDOW_H);
	w->md = point_set(0, 0);
	w->mu = point_set(0, 0);
	w->mm = point_set(0, 0);
	w->zoom = INITIAL_ZOOM;
	w->shift = point_set(0, 0);
	w->scale = 1.0;
	w->palette = 0x0003F40B;
	w->iteractions = MAX_ITERATIONS;
	set_init_values_img(w);
}

t_win	win_init(char *title)
{
	t_win	w;

	set_init_values_win(&w, title);
	w.mlx_ptr = mlx_init();
	printf("mlx_init ha devuelto %p\n", w.mlx_ptr);
	if (w.mlx_ptr == NULL)
		exit (-1);
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.size.x, w.size.y, w.title);
	printf("mlx_new_window ha devuelto %p\n", w.win_ptr);
	if (w.win_ptr == NULL)
	{
		free(w.mlx_ptr);
		exit (-1);
	}
	w.img.img_ptr = mlx_new_image(w.mlx_ptr, w.img.size.x, w.img.size.y);
	printf("mlx_new_image ha devuelto %p\n", w.img.img_ptr);
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
/*	printf("win %s bit per pixel %d, line_length %d endian %d\n",
		w.title,
		w.img.bits_per_pixel,
		w.img.line_length,
		w.img.endian,
		w.img.addr);
		*/
