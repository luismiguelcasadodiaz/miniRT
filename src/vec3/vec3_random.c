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

void	vec3_inside_unit_sphere(t_vec3 *r)
{
	double	aux;

	r->e[0] = ft_rand(-1.0, 1.0);
	if (r->e[0] == 1 || r->e[0] == -1.0)
	{
		r->e[1] = 0;
		r->e[2] = 0;
	}
	else
	{
		r->e[1] = ft_rand(-1.0, 1.0);
		if (r->e[1] == 1 || r->e[1] == -1.0)
		{
			r->e[0] = 0;
			r->e[2] = 0;
		}
		else
		{
			aux = r->e[0] * r->e[0] + r->e[1] * r->e[1];
			if (aux == 1)
				r->e[2] = 0;
			else
				r->e[2] = ft_rand(-sqrt(1 - aux), sqrt(1 - aux));
		}
	}
}

// generates a normalized vector inside the unit sphere
// but outside the blackhole that makes length almost zero
void	vec3_nius(t_vec3 *r)
{
	int		accepted;
	double	length;

	accepted = 0;
	while (!accepted)
	{
		vec3_inside_unit_sphere(r);
		length = vec3_length(r);
		accepted = (1e-160 < length);
	}
	vec3_scale(r, r, length);
}

void	vec3_random_on_hemisphere(t_vec3 *normal, t_vec3 *result)
{
	vec3_nius(result);
	if (vec3_dot(normal, result) < 0.0)
		vec3_negate(result, result);
}
