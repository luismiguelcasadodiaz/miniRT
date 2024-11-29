/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:58:39 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/13 18:38:20 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GETNL_H
# define GETNL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 43
# endif

size_t	gnl_strlen(char	*s);
size_t	gnl_strlen_and_nl(ssize_t *pos, char	*s);
char	*gnl_substr(char *str, unsigned int start, size_t len);
char	*gnl_join(char *buf, char *raw);
char	*get_next_line(int fd);
char	*my_free(char **ptr);
#endif 
