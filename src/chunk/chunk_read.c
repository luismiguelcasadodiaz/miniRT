/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:17:32 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/13 17:43:00 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnl.h"
#include "libft.h"
#include "chunk.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static void	final_check(t_win *w, char **errmsg, char *filename)
{
	if (!w->camera || !w->ambient || !w->light)
		error_bad_scene(filename, errmsg);
	else
		camer_calc_background_colors_ambil(w->camera, w->ambient->color);
}

void	chunk_treat_line(char *line, char **errmsg, t_win *w)
{
	t_eleme_chunks	*chunks;
	char			*trimmed_line;

	trimmed_line = ft_strtrim(line, " \n");
	chunks = (t_eleme_chunks *)malloc(sizeof(t_eleme_chunks));
	if (ft_strlen(trimmed_line) != 1)
	{
		ft_split_minrt(trimmed_line, " \t", &(chunks->line));
		if (ft_strlen(chunks->line.param[0]) == 1)
			treat_one_letter_command(chunks, errmsg, w);
		else if (ft_strlen(chunks->line.param[0]) == 2)
			treat_two_letter_command(chunks, errmsg, w);
		else
			error_bad_letter_command(&(chunks->line), errmsg);
		de_allocate(chunks->line.param, chunks->line.num);
	}
	free(chunks);
	free(trimmed_line);
}
//	printf("lin>%s< tiene %ld cars\n", trimmed_line, ft_strlen(trimmed_line));
//chunk_print(&(chunks->line));

void	chunk_read(char *filename, char **errmsg, t_win *w)
{
	int		fd;
	short	end_file;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error_bad_file(filename, errmsg);
		return ;
	}
	end_file = 0;
	while (!end_file && !*errmsg)
	{
		line = get_next_line(fd);
		if (line == NULL)
			end_file = 1;
		else if (ft_strlen(line) != 1)
			chunk_treat_line(line, errmsg, w);
		free(line);
	}
	close(fd);
	if (*errmsg)
		return ;
	final_check(w, errmsg, filename);
}

/*if (ft_strlen(line) == 1)
			printf("El descriptor de escenas tiene lineas vacías\n");
		else*/
