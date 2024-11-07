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

typedef struct s_eleme_chunks
{
	t_chunk	line;
	t_chunk	coor;
	t_chunk	novec;
	t_chunk	color;
	char	*diam;
	char	*hfov;	
	char	*lbf;
	char	*height;
}	t_eleme_chunks;

// chunk_read.c
void	chunk_read(char *filename, char **errmsg, t_win *w);
void	chunk_treat_line(char *line, char **errmsg, t_win *w);	
// chunk_treatments_one.c
void	treat_one_letter_command(t_eleme_chunks chunks, char **errmsg, t_win *w);
void	treat_two_letter_command(t_eleme_chunks chunks, char **errmsg, t_win *w);
void	treat_ambient(t_eleme_chunks chunks, char **errmsg, t_win *w);
void	treat_camera(t_eleme_chunks chunks, char **errmsg, t_win *w);
void	treat_light(t_eleme_chunks chunks, char **errmsg, t_win *w);
// chunk_treatments_two.c
void	treat_sphere(t_eleme_chunks chunks, char **errmsg, t_win *w);
void	treat_plane(t_eleme_chunks chunks, char **errmsg, t_win *w);
void	treat_cylin(t_eleme_chunks chunks, char **errmsg, t_win *w);

// chunk_transfer_values.c
void	trans_sphere(t_win *w, t_eleme_chunks chunks, char ** errmsg);
void	trans_plane(t_win *w, t_eleme_chunks chunks, char ** errmsg);
void	trans_cylin(t_win *w, t_eleme_chunks chunks, char ** errmsg);
// chunk_errors_one.c
void	error_bad_letter_command(t_chunk chunks, char **errmsg);
void	error_bad_number_argumen(t_chunk chunks, char **errmsg);
void	error_bad_color_num_argu(t_chunk chunks, char **errmsg);
void	error_bad_point_num_argu(t_chunk chunks, char **errmsg);
void	error_bad_color_range(t_chunk chunks, char **errmsg);
// chunk_errors_two.c
void	error_bad_diam(char *diam, char **errmsg, enum e_eleme obj);
void	error_bad_heig(char *diam, char **errmsg, enum e_eleme obj);
void	error_normal_bad_num_argu(t_chunk chunks, char **errmsg);
void	error_normal_bad_range(t_chunk chunks, char **errmsg);
void	error_normal_zero(t_chunk chunks, char **errmsg);

// chunk_errors_three.c
void	error_not_implemented(char *proc, char **errmsg);

// chunk_print.c
void	chunk_print(t_chunk chunks);
#endif