/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:24:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/01 08:26:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHUNK_H
# define CHUNK_H
# include <stdlib.h>
# include "miniRT.h"

typedef struct s_chunk
{
	char	**param;
	size_t	num;
}	t_chunk;

// chunk_read.c
void	chunk_read(char *filename, char **errmsg, t_win *w);
void	chunk_treat_line(char *line, char **errmsg, t_win *w);	
// chunk_treatments_one.c
void	treat_one_letter_command(t_chunk chunks, char **errmsg, t_win *w);
void	treat_two_letter_command(t_chunk chunks, char **errmsg, t_win *w);
void	treat_ambient(t_chunk chunks, char **errmsg, t_win *w);
void	treat_camera(t_chunk chunks, char **errmsg, t_win *w);
void	treat_light(t_chunk chunks, char **errmsg, t_win *w);
// chunk_treatments_two.c
void	treat_sphere(t_chunk chunks, char **errmsg, t_win *w);
void	treat_plane(t_chunk chunks, char **errmsg, t_win *w);
void	treat_cylin(t_chunk chunks, char **errmsg, t_win *w);

// chunk_transfer_values.c
void	trans_sphere(t_win *w, t_chunk coor, double diameter, t_chunk color);
// chunk_errors_one.c
void	error_bad_letter_command(t_chunk chunks, char **errmsg);
void	error_bad_number_argumen(t_chunk chunks, char **errmsg);
void	error_bad_color_num_argu(t_chunk chunks, char **errmsg);
void	error_bad_point_num_argu(t_chunk chunks, char **errmsg);
// chunk_print.c
void	chunk_print(t_chunk chunks);
#endif