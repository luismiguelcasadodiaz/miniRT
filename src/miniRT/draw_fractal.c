/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:13:27 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/21 14:11:45 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx.h"
#include "libft.h"
#include <unistd.h>

void	draw_fractal(t_win w)
{
	show_data(w);
	draw_image4(&w);
	return ;
}
	//draw_image1(w);
	//draw_image2(&w);
	//draw_image3(&w);
