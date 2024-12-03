/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_image_to_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 01:00:42 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/05 01:11:04 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mlx_put_image_to_window.c for MiniLibX in raytraceur
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Aug 14 15:55:49 2000 Charlie Root
** Last update Sun Oct  2 09:53:00 2005 Olivier Crouzet
*/

#include "mlx_int.h"

int	mlx_put_image_to_window(t_xvar *xvar, t_win_list *w, t_img *i, int x, int y)
{
	GC	gc;

	gc = w->gc;
	if (i->gc)
	{
		gc = i->gc;
		XSetClipOrigin(xvar->display, gc, x, y);
	}
	if (i->type == MLX_TYPE_SHM)
		XShmPutImage(xvar->display, i->pix, w->gc, i->image,
			0, 0, 0, 0, i->width, i->height, False);
	if (i->type == MLX_TYPE_XIMAGE)
		XPutImage(xvar->display, i->pix, w->gc, i->image,
			0, 0, 0, 0, i->width, i->height);
	XCopyArea(xvar->display, i->pix, w->window, gc,
		0, 0, i->width, i->height, x, y);
	if (xvar->do_flush)
		XFlush(xvar->display);
}
