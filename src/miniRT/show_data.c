/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:24:03 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/16 15:56:56 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

void	show_data(t_win w)
{
	printf("===============================\n");
	printf("window size:\t(%d, %d)\n", (int)w.size->x, (int)w.size->y);
	printf("image size:\t(%d, %d)\n", (int)w.img.size->x, (int)w.img.size->y);
	printf("bpp =(%d)\n", w.img.bits_per_pixel);
	printf("ll=(%d)\n", w.img.line_length);
	printf(" addr=(%s)\n", w.img.addr);
	printf("===============================\n");
}
