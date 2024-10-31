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
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
static void treat_one_letter_command(char **chunks, char **errmsg)
{
	if (ft_strncmp(chunks[0], 'A', 1))
		treat_ambient(chunks, errmsg);
	else if (ft_strncmp(chunks[0], 'C', 1))
		treat_camera(chunks, errmsg);
	else if (ft_strncmp(chunks[0], 'L', 1))
		treat_light(chunks, errmsg);
	else
		error_bad_letter_command(chunks, **errmsg);
}

static void treat_two_letter_command(char **chunks, char **errmsg)
{
	if (ft_strncmp(chunks[0], 'sp', 2))
		treat_sphere(chunks, errmsg);
	else if (ft_strncmp(chunks[0], 'pl', 2))
		treat_plane(chunks, errmsg);
	else if (ft_strncmp(chunks[0], 'cy', 2))
		treat_cylin(chunks, errmsg);
	else
		error_bad_letter_command(chunks, **errmsg);
}
static void	treat_line(char *line, char **errmsg)
{
	char	**chunks;
	char	*trimmed;
	size_t	numchunks;
	int		i;

	i = 0;
	printf("%s", line);
	chunks = ft_split_minrt(line, ' ', &numchunks);
	if (ft_strlen(chunks[0]) == 1)
		treat_one_letter_command(chunks, **errmsg);
	else if (ft_strlen(chunks[0]) == 2)
		treat_two_letter_command(chunks, **errmsg);
	else
		error_bad_letter_command(chunks, **errmsg);

	de_allocate(chunks, numchunks);
}

void	read_file(char *filename, char **errmsg)
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
			treat_line(line, errmsg);
		free(line);
	}
	close(fd);
}

