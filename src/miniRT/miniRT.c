/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:28:52 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/30 23:37:27 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "miniRT.h"

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

int	main(int argc, char **argv)
{
	t_win	w;
	char	*errmsg;

	errmsg = NULL;
	if (argc != 2)
	{
		show_usage();
		return (0);
	}
	read_file(argv[1], &errmsg);
	if (errmsg)
	{
		printf("Error\n%s\n", errmsg);
		exit (1);
	}
	w = win_init(argv[1]);
	mlx_hook(w.win_ptr, ON_KEYDOWN, (1L << 0), &win_h_key_down, &w);
	mlx_hook(w.win_ptr, ON_KEYUP, 0L, &win_h_key_up, &w);
	mlx_hook(w.win_ptr, ON_EXPOSE, 0L, &win_h_expose, &w);
	mlx_hook(w.win_ptr, ON_DESTROY, 0L, &win_h_destroy, &w);
	mlx_loop_hook(w.mlx_ptr, &win_h_not_event, &w);
	mlx_loop(w.mlx_ptr);
	win_free(w);
	return (0);
}

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
