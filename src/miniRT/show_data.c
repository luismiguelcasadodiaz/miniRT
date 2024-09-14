/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:24:03 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/13 08:44:14 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

void	show_data(t_win w)
{
	printf("===============================\n");
	printf("window size:\t(%d, %d)\n", w.size->x, w.size->y);
//	printf("window coor:\t lu=(%d, %d)", w.lu.x, w.lu.y);
//	printf("	.. rd=(%d, %d)\n", w.rd.x, w.rd.y);
//	printf("mouse down:\t(%d, %d)\n", w.md.x, w.md.y);
//	printf("mouse up:\t(%d, %d)\n", w.mu.x, w.mu.y);
//	printf("mouse move:\t(%d, %d)\n", w.mm.x, w.mm.y);
//	printf("shift:\t(%d, %d)\n", w.shift.x, w.shift.y);
//	printf("zoom:\t %d\n", w.zoom);
//	printf("iterations:\t%d\n", w.iteractions);
	printf("image size:\t(%d, %d)\n", w.img.size->x, w.img.size->y);
//	printf("image coor:\t lu=(%d, %d)", w.img.lu.x, w.img.lu.y);
//	printf("	.. rd=(%d, %d)\n", w.img.rd.x, w.img.rd.y);
//	printf("image (0, 0):\t(%d, %d)\n", w.img.x_0, w.img.y_0);
	printf("bpp =(%d)\n", w.img.bits_per_pixel);
	printf("ll=(%d)\n", w.img.line_length);
	printf(" addr=(%s)\n", w.img.addr);
	printf("===============================\n");
}
