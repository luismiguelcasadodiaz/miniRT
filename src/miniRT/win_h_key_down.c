/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_key_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:19:34 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/03 19:03:18 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_ubuntu_home.h"
#include "miniRT.h"
#include <stdio.h>
#include "mlx.h"
/*
static void	arrows(int keysym, t_win *w)
{
	if (keysym == ARROW_DOWN)
	{
		w->img.lu.y += 10;
		w->img.rd.y += 10;
		w->shift.y += 10;
	}
	if (keysym == ARROW_UP)
	{
		w->img.lu.y -= 10;
		w->img.rd.y -= 10;
		w->shift.y -= 10;
	}
	if (keysym == ARROW_LEFT)
	{
		w->img.lu.x += 10;
		w->img.rd.x += 10;
		w->shift.x += 10;
	}
	if (keysym == ARROW_RIGHT)
	{
		w->img.lu.x -= 10;
		w->img.rd.x -= 10;
		w->shift.x -= 10;
	}
}

static void	iteractions(int keysym, t_win *w)
{
	if (keysym == NUMPAD_KEY_PLUS)
		w->iteractions++;
	if (keysym == NUMPAD_KEY_MINUS && w->iteractions > MAX_ITERATIONS)
		w->iteractions--;
	w->palette = 0x00FFFFFF / w->iteractions;
}
*/
int	win_h_key_down(int keysym, t_win *w)
{
	if (keysym == KEY_ESC)
	{
		mlx_destroy_window(w->mlx_ptr, w->win_ptr);
		win_free(*w);
		free(w->mlx_ptr);
		exit (0);
	}
	if (keysym == KEY_R)
		col_init_with_1(w->camera->color_end, 0.9607, 0.4627, 0.5372);
	if (keysym == KEY_G)
		col_init_with_1(w->camera->color_end, 0.584, 0.8588, 0.6588);
	if (keysym == KEY_B)
		col_init_with_1(w->camera->color_end, 0.5, 0.7, 1.0);
	draw_fractal(*w);
	printf("Key_down: %d\n", keysym);
	return (0);
}
/*	if (keysym == KEY_S)
		w->palette = 0x0003F40B;
	if (keysym == NUMPAD_KEY_PLUS || keysym == NUMPAD_KEY_MINUS)
		iteractions(keysym, w);
	if ((ARROW_LEFT <= keysym) && (keysym <= ARROW_UP))
		arrows(keysym, w);
	*/
