/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genimage.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:34:13 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/05 23:57:20 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GENIMAGE_H
# define GENIMAGE_H

typedef struct s_f_color
{
	float	red;
	float	gre;
	float	blu;
}			t_f_color;

typedef struct s_i_color
{
	int	red;
	int	gre;
	int	blu;
}			t_i_color;

typedef struct s_win
{
	int	w;
	int	h;
}		t_win;
#endif
