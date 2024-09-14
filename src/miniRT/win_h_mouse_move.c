/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:40:21 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/13 08:57:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	win_h_mouse_move(int x, int y, t_win *w)
{
	if ((0 <= x && x <= w->size->x) && (0 <= y && y <= w->size->y))
		x += y;
//		w->mm = point_set(x, y);
	return (0);
}
