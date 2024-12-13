/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:28:52 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/02 14:07:40 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "miniRT.h"
#include "chunk.h"
#include "libft.h"

/* ************************************************************************** */
/**
   @file main.c
   @brief main() helps tha author to learnt minilibx

   @param[in]  s: The stack to calculate value's future positions.

   @details
   mlx_init() initializes the conexion with the windows enviroment, eithe X
   or opengl.

   mlx_init returns a void * pointer wha have to check for error.

   Loops the stack. For each node loops the stack couting how manu values
   are lower than current (external loop node) node's value.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
//https://aurelienbrabant.fr/blog/events-with-the-minilibxi
//https://03-jon-perez.gitbook.io/coding-library/c/minilibx
//https://harm-smits.github.io/42docs/libs/minilibx


// address memory of filename init minus address memory
// os last point give me number of letters before the last  point
// len minus number of letters till last point gives exension lenth
static int	bad_file_extension(char **argv)
{
	int len;
	char *last_point;
	int pos;

	len = (int)ft_strlen(argv[1]);
	last_point = ft_strrchr(argv[1], '.');
	pos = (int)(last_point - argv[1]);
	if (len - pos != 3)
	{
		printf("The filename %s has not two letters extension\n", argv[1]);
		return (1);
	}
	else if ((argv[1][len - 2] != 'r') || (argv[1][len - 1] != 't' ))
	{
		printf("Filename %s extension incorrect \n", argv[1]);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	w;
	char	*errmsg;

	errmsg = NULL;
	if ((argc != 2) || bad_file_extension(argv))
	{
		show_usage();
		return (0);
	}
	w = win_init(argv[1]);
	chunk_read(argv[1], &errmsg, &w);
	if (errmsg)
	{
		win_free(w);
		printf("Error\n%s\n", errmsg);
		exit (1);
	}
	mlx_hook(w.win_ptr, ON_KEYDOWN, (1L << 0), &win_h_key_down, &w);
	mlx_hook(w.win_ptr, ON_KEYUP, 0L, &win_h_key_up, &w);
	mlx_hook(w.win_ptr, ON_EXPOSE, 0L, &win_h_expose, &w);
	mlx_hook(w.win_ptr, ON_DESTROY, 0L, &win_h_destroy, &w);
	mlx_loop_hook(w.mlx_ptr, &win_h_not_event, &w);
	mlx_loop(w.mlx_ptr);
	win_free(w);
	return (0);
}
	//eleme_print(w.eleme);
	//camer_print(w.camera);
	// ambil_print(w.ambient);
	// light_print(w.light);
/* At home with UBUNTU
	mlx_hook(w.win_ptr, ON_KEYDOWN, (1L << 0), &win_h_key_down, &w);
	mlx_hook(w.win_ptr, ON_KEYUP, 0L, &win_h_key_up, &w);
	mlx_hook(w.win_ptr, ON_MOUSEDOWN, (1L << 2), &win_h_mouse_down, &w);
	mlx_hook(w.win_ptr, ON_MOUSEUP, 0L, &win_h_mouse_up, &w);
	mlx_hook(w.win_ptr, ON_MOUSEMOVE, (1L << 6), &win_h_mouse_move, &w);
	mlx_hook(w.win_ptr, ON_EXPOSE, 0L, &win_h_expose, &w);
	mlx_hook(w.win_ptr, ON_DESTROY, 0L, &win_h_destroy, &w);
	*/
//	mlx_hook(w.win_ptr, ON_MOUSEDOWN, (1L << 2), &win_h_mouse_down, &w);
//	mlx_hook(w.win_ptr, ON_MOUSEUP, 0L, &win_h_mouse_up, &w);
//	mlx_hook(w.win_ptr, ON_MOUSEMOVE, (1L << 6), &win_h_mouse_move, &w);
/*	mlx_hook(w.win_ptr, ON_KEYDOWN, 0, &win_h_key_down, &w);
	mlx_hook(w.win_ptr, ON_KEYUP, 0, &win_h_key_up, &w);
	mlx_hook(w.win_ptr, ON_MOUSEDOWN, 0, &win_h_mouse_down, &w);
	mlx_hook(w.win_ptr, ON_MOUSEUP, 0, &win_h_mouse_up, &w);
	mlx_hook(w.win_ptr, ON_MOUSEMOVE, 0, &win_h_mouse_move, &w);
	mlx_hook(w.win_ptr, ON_EXPOSE, 0, &win_h_expose, &w);
	mlx_hook(w.win_ptr, ON_DESTROY, 0, &win_h_destroy, &w);
*/
