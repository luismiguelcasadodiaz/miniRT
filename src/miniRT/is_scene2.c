/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_scene2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:46:50 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/14 15:17:52 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "miniRT.h"
#include "mlx.h"
#include <stdio.h>

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

	vec3_mul_lmcd(&aux, w->pd_x, x);
	vec3_copy_values(w->ray_direction, w->pixel00);
	vec3_add(w->ray_direction, w->ray_direction, &aux);
	vec3_mul_lmcd(&aux, w->pd_y, y);
	vec3_add(w->ray_direction, w->ray_direction, &aux);
	vec3_init_values(&aux, w->cc->x, w->cc->y, w->cc->z);
	vec3_sub(w->ray_direction, w->ray_direction, &aux);
}

void	draw_image2(t_win *w)
{
	int			wx0;
	int			wy0;
	int			mlx_color;
	t_ray		*r;

	r = ray_new();
	wy0 = w->lu->y;
	while (wy0 <= w->rd->y)
	{
		fprintf(stderr, "\rLines remaining: %*d", 5, w->rd->y - wy0);
		wx0 = w->lu->x;
		while (wx0 <= w->rd->x)
		{
			win_calculate_ray_dir(w, wx0, wy0);
			ray_init(r, w->cc, w->ray_direction);
			mlx_color = ray_color(r);
			win_pixel_put(*w, wx0, wy0, mlx_color);
			wx0++;
		}
		fprintf(stderr, "y=%d , color=%d\n", wy0, mlx_color);
		wy0++;
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img.img_ptr, 0, 0);
	ray_free(r);
}
