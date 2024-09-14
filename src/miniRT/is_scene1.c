/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_scene1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:56:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/14 10:51:38 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx.h"
#include <stdio.h>

static int	make_my_color(t_point *size, int x, int y)
{
	t_color	*color;
	int		mlx_color;

	color = col_new();
	col_init_with_1(color,
		(double)x / (size->x - 1),
		(double)y / (size->y - 1),
		(double)0.0);
	mlx_color = col_get_mlx_color(color);
	col_free(color);
	return (mlx_color);
}

void	draw_image1(t_win w)
{
	int			wx0;
	int			wy0;

	wy0 = w.lu->y;
	while (wy0 <= w.rd->y)
	{
		fprintf(stderr, "\rLines remaining: %*d", 5, w.rd->y - wy0);
		wx0 = w.lu->x;
		while (wx0 <= w.rd->x)
		{
			win_pixel_put(w, wx0, wy0, make_my_color(w.rd, wx0, wy0));
			wx0++;
		}
		wy0++;
	}
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img.img_ptr, 0, 0);
}
