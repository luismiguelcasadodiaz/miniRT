/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:32:45 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/16 15:51:45 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>
#include "keys_ubuntu_42.h"
/*
static void	calculate_shift_x(int x, t_win *w)
{
	int	a;

	if (x > w->mm.x)
	{
		a = (x - w->mm.x) / w->scale;
		w->shift.x += a;
		w->img.lu.x += a;
		w->img.rd.x += a;
	}
	else
	{
		a = (w->mm.x - x) / w->scale;
		w->shift.x -= a;
		w->img.lu.x -= a;
		w->img.rd.x -= a;
	}
}

static void	calculate_shift_y(int y, t_win *w)
{
	int	a;

	if (y > w->mm.y)
	{
		a = (y - w->mm.y) / w->scale;
		w->shift.y += a;
		w->img.lu.y += a;
		w->img.rd.y += a;
	}
	else
	{
		a = (w->mm.y - y) / w->scale;
		w->shift.y -= a;
		w->img.lu.y -= a;
		w->img.rd.y -= a;
	}
}

static void	calculate_shift(int x, int y, t_win *w)
{
	calculate_shift_x(x, w);
	calculate_shift_y(y, w);
}
*/
int	win_h_mouse_down(int button, int x, int y, t_win *w)
{
	draw_fractal(*w);
	printf("dowm (%d, %d) button %d \n", x, y, button);
	return (0);
}
/*	if (button == MOUSE_SCROLL_DOWN)
	{
		w->zoom++;
		w->scale *= ZOOM_FACTOR;
		calculate_shift(x, y, w);
		draw_fractal(*w);
	}
	else if (button == MOUSE_SCROLL_UP)
	{
		w->zoom--;
		w->scale *= (1 / ZOOM_FACTOR);
		calculate_shift(x, y, w);
		draw_fractal(*w);
	}
	else if (button == MOUSE_BUTTON_LEFT)
	{
		w->md = point_set(x, y);
		draw_fractal(*w);
	}
*/
	//printf("dowm (%d, %d) button %d zoom %d \n", x, y, button, w->zoom);
