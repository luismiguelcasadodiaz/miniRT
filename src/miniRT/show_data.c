/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:24:03 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/02 19:59:20 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

void	show_data(t_win w)
{
	printf("===============================\n");
	printf("window size:\t(%d, %d)\n", (int)w.size->e[0], (int)w.size->e[1]);
	printf("img :\t(%d, %d)\n", (int)w.img.size->e[0], (int)w.img.size->e[1]);
	printf("bpp =(%d)\n", w.img.bits_per_pixel);
	printf("ll=(%d)\n", w.img.line_length);
	printf(" addr=(%s)\n", w.img.addr);
	printf("===============================\n");
}
