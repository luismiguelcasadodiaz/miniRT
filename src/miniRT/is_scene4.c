/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_scene4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:46:50 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/27 20:26:06 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "miniRT.h"
#include "mlx.h"
#include <stdio.h>
#include "vec3.h"
#include "color.h"

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

	vec3_mul(&aux, w->pd_x, x);
	vec3_copy_values(w->ray_direction, w->pixel00);
	vec3_add(w->ray_direction, w->ray_direction, &aux);
	vec3_mul(&aux, w->pd_y, y);
	vec3_add(w->ray_direction, w->ray_direction, &aux);
	vec3_init_values(&aux, w->cc->e[0], w->cc->e[1], w->cc->e[2]);
	vec3_sub(w->ray_direction, w->ray_direction, &aux);
}

static void	world_destroy(t_win *w)
{
	eleme_free(w->eleme);
}

static void	world_create(t_win *w)
{
	t_vec3	center;
	t_color	*rgb255;

	rgb255 = col_new();
	vec3_init_values(&center, 0, 0, -1);
	col_init_with_255(rgb255, 255, 0, 0);
	w->eleme = eleme_new_sph(&center, 0.5, rgb255);
	eleme_print(w->eleme);
	col_free(rgb255);
}

void	draw_image4(t_win *w)
{
	int			wx0;
	int			wy0;
	int			mlx_color;
	t_ray		*r;

	world_create(w);
	r = ray_new();
	wy0 = w->lu->e[1];
	while (wy0 <= w->rd->e[1])
	{
		//fprintf(stderr, "\rLines remaining: %*d", 5, (int)w->rd->e[1] - wy0);
		wx0 = w->lu->e[0];
		while (wx0 <= w->rd->e[0])
		{
			win_calculate_ray_dir(w, wx0, wy0);
			ray_init(r, w->cc, w->ray_direction);
			mlx_color = ray_color(r, *w->color_start, *w->color_end, w->eleme);
			win_pixel_put(*w, wx0, wy0, mlx_color);
			wx0++;
			//fprintf(stderr, "x=%d, y=%d , color=%d\n", wx0, wy0, mlx_color);
		}
		//fprintf(stderr, "y=%d , color=%d\n", wy0, mlx_color);
		wy0++;
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img.img_ptr, 0, 0);
	ray_free(r);
	world_destroy(w);
}
