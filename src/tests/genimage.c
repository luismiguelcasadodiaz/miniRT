/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genimage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:21:15 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/06 01:05:04 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "genimage.h"

static FILE	*open_and_header(char *name, t_win win)
{
	FILE		*fd;

	fd = fopen(name, "w");
	fprintf(fd, "P3\n");
	fprintf(fd, "%d %d\n", win.w, win.h);
	fprintf(fd, "255\n");
	return (fd);
}

static void	write_image(FILE *fd, t_win win)
{
	t_win		idx_w;
	t_f_color	f_color;
	t_i_color	i_color;

	idx_w.h = -1;
	printf("\n");
	while (++idx_w.h < win.h)
	{
		printf("Generating line %*d/%d\r", 6, idx_w.h, win.h);
		idx_w.w = -1;
		while (++idx_w.w < win.w)
		{
			f_color.red = (float)idx_w.w / (win.w - 1);
			f_color.gre = (float)idx_w.h / (win.h - 1);
			f_color.blu = 0.0;
			i_color.red = (int)(255.999 * f_color.red);
			i_color.gre = (int)(255.999 * f_color.gre);
			i_color.blu = (int)(255.999 * f_color.blu);
			fprintf(fd, "%d %d %d\n", i_color.red, i_color.gre, i_color.blu);
		}
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_win		win;
	FILE		*fd;

	if (argc != 4)
	{
		printf("Usage: genimage <int width> <int heigth> filename\n");
		exit(0);
	}
	win.w = atoi(argv[1]);
	win.h = atoi(argv[2]);
	fd = open_and_header(argv[3], win);
	write_image(fd, win);
	pclose(fd);
}
