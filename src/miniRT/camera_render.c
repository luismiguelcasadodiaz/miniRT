/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:46:50 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/02 14:06:23 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "miniRT.h"
#include "../minilibx/mlx.h"
#include <stdio.h>
#include "vec3.h"
#include "color.h"
#include "libft.h"

/*static int	make_my_color(t_point *size, int x, int y)
{
	double	fx;
	double	fy;

	fx = (double)x / (size->x - 1);
	fy = (double)y / (size->y - 1);
	return (col_create_double(0, fx, fy, 0));
}*/

/******************************************************************************/
/* Ray Directio = pixel center . camera center                                */
/* pixel center = P00 + x * pd_x + y * pd_y                                   */
/*                                                                            */
/* Ray Direction = P00 + x * pd_x + y * pd_y - camera center                  */
/******************************************************************************/

static void	win_calculate_ray_dir(t_win *w, int x, int y)
{
	t_vec3	aux;

	vec3_mul(&aux, &w->camera->pd_u, ((double)x + (double)ft_rand(-0.5, 0.5)));
	vec3_copy_values(w->ray_direction, &w->camera->pixel00_loc);
	vec3_add(w->ray_direction, w->ray_direction, &aux);
	vec3_mul(&aux, &w->camera->pd_v, ((double)y + (double)ft_rand(-0.5, 0.5)));
	vec3_add(w->ray_direction, w->ray_direction, &aux);
	vec3_init_values(&aux, w->camera->lookfrom.e[0],
		w->camera->lookfrom.e[1], w->camera->lookfrom.e[2]);
	vec3_sub(w->ray_direction, w->ray_direction, &aux);
}

//para promediar, hay que sumar los colores sin limite. por eso uso vec3_add
static int	antialiasing(t_win *w, int x, int y, t_ray *r)
{
	int		sample;
	t_color	color;
	t_color	one_color;

	col_init_with_1(&color, 0, 0, 0);
	sample = 0;
	while (sample < w->camera->samples_per_pixel)
	{
		win_calculate_ray_dir(w, x, y);
		ray_init(r, &w->camera->lookfrom, w->ray_direction);
		one_color = ray_color(r, w);
		vec3_add(&color.rgb, &color.rgb, &one_color.rgb);
		sample++;
	}
	col_scale(&color, &color, (1.0 / w->camera->samples_per_pixel));
	return (col_get_mlx_color(&color));
}

// For each image's (x,y) calculates the world's coordinate's color 
void	camera_render(t_win *w)
{
	int			wx0;
	int			wy0;
	int			mlx_color;
	t_ray		*r;

	r = ray_new();
	wy0 = (int)w->lu->e[1];
	while (wy0 <= w->rd->e[1])
	{
		fprintf(stderr, "\rScanlines remaining: %d ", (int)w->rd->e[1] - wy0);
		wx0 = (int)w->lu->e[0];
		while (wx0 <= w->rd->e[0])
		{
			mlx_color = antialiasing(w, wx0, wy0, r);
			win_pixel_put(*w, wx0, wy0, mlx_color);
			wx0++;
		}
		wy0++;
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img.img_ptr, 0, 0);
	ray_free(r);
}
