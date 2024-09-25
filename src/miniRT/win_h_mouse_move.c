/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:40:21 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/25 20:13:42 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	win_h_mouse_move(int x, int y, t_win *w)
{
	if ((0 <= x && x <= w->size->e[0]) && (0 <= y && y <= w->size->e[1]))
		x += y;
	return (0);
}
//		w->mm = point_set(x, y);
