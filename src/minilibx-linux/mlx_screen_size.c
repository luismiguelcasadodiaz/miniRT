/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_screen_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:48:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/04 19:50:25 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
{
	XWindowAttributes	xwattr;
	Status				ret;
	t_xvar				*xvar;

	xvar = mlx_ptr;
	ret = XGetWindowAttributes(xvar->display, xvar->root, &xwattr);
	(*sizex) = xwattr.width;
	(*sizey) = xwattr.height;
}
