/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_scene1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:56:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/07 10:44:53 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx.h"

static t_color	make_my_color(t_point size, int x, int y)
{
	t_color	c;
	float	fx;
	float	fy;

	fx = (float)x / (size.x - 1);
	fy = (float)y / (size.y - 1);
	c.r = (int)(255.999 * fx);
	c.g = (int)(255.999 * fy);
	c.b = 0;
	c.t = 0;
	return (c);
}

void	draw_image1(t_win w)
{
	int			wx0;
	int			wy0;
	t_color		c;

	wy0 = w.lu.y;
	while (wy0 <= w.rd.y)
	{
		wx0 = w.lu.x;
		while (wx0 <= w.rd.x)
		{
			c = make_my_color(w.rd, wx0, wy0);
			win_pixel_put(w, wx0, wy0, col_create(c.t, c.r, c.g, c.b));
			wx0++;
		}
		wy0++;
	}
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img.img_ptr, 0, 0);
}
