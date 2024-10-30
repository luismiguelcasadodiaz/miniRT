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

void	read_file(char *filename)
{
	int		fd;
	short	end_file;
	char	*line;
	char	**chunks;

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
		{
			printf("%s", line);
			chunks = ft_split(line, ' ');
			while (chunks[0])
			{
				printf("%s\n", ft_strtrim(chunks[0], " "));
				chunks++;
				
			}
		}
		free(line);
	}
	close(fd);
}

