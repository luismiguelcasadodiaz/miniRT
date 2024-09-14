/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:39:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/12 21:20:16 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

int	win_h_mouse_up(int button, int x, int y, t_win *w)
{
	printf("w=%s, mouse_up (%d, %d) button %d\n", w->title, x, y, button);
//	w->mu = point_set(x, y);
	return (0);
}
