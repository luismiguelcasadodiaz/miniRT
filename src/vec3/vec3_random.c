/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:53:28 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/27 19:53:30 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec3.h"
#include "stdlib.h"
#include "libft.h"

void	vec3_random(t_vec3	*s, float min, float max)
{
	vec3_init_values(s,
		ft_rand(min, max),
		ft_rand(min, max),
		ft_rand(min, max));
}

void	vec3_sample_square(t_vec3 *n)
{
	float	min;
	float	max;

	min = -0.5;
	max = 0.5;
	vec3_init_values(n, ft_rand(min, max), ft_rand(min, max), 0);
}
