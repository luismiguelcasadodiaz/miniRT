/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:17:32 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/30 23:36:00 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnl.h"
#include "libft.h"
#include "chunk.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void	chunk_treat_line(char *line, char **errmsg, t_win *w)
{
	t_chunk	chunks;

	printf("%s", line);
	ft_split_minrt(line, ' ', &chunks);
	chunk_print(chunks);
	if (ft_strlen(chunks.param[0]) == 1)
		treat_one_letter_command(chunks, errmsg, w);
	else if (ft_strlen(chunks.param[0]) == 2)
		treat_two_letter_command(chunks, errmsg, w);
	else	
		error_bad_letter_command(chunks, errmsg);
	
	de_allocate(chunks.param, chunks.num);
}

void	chunk_read(char *filename, char **errmsg, t_win *w)
{
	int		fd;
	short	end_file;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Problems opening <%s> file \n", filename);
		return ;
	}
	end_file = 0;
	while (!end_file)
	{
		line = get_next_line(fd);
		if (line == NULL)
			end_file = 1;
		else
			chunk_treat_line(line, errmsg, w);
		free(line);
	}
	close(fd);
}

