/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:39:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/16 15:50:35 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

int	win_h_mouse_up(int button, int x, int y, t_win *w)
{
	printf("w=%s, mouse_up (%d, %d) button %d\n", w->title, x, y, button);
	return (0);
}
//	w->mu = point_set(x, y);
