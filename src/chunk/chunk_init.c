/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:23:48 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/14 17:58:17 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "libft.h"
#define X 0
#define Y 1
#define Z 2

float	trans_atof(char *s, char **errmsg)
{
	char	*txt;
	int		sign;
	int		dot;

	txt = s;
	dot = 0;
	sign = 0;
	while (*txt)
	{
		if (!(*txt == '+' || *txt == '-' || *txt == '.' || ft_isdigit(*txt)))
		{
			error_bad_float_txt(s, errmsg);
			return (0);
		}
		sign += ((*txt == '+') || (*txt == '-' ));
		dot += (*txt == '.');
		txt++;
	}
	if (dot > 1 || sign > 1)
	{
		error_bad_float_txt(s, errmsg);
		return (0);
	}
	return (ft_atof(s));
}

int	trans_atoi(char *s, char **errmsg)
{
	char	*txt;
	int		sign;

	txt = s;
	sign = 0;
	while (*txt)
	{
		if (!(*txt == '+' || *txt == '-' || ft_isdigit(*txt)))
		{
			error_bad_int_txt(s, errmsg);
			return (0);
		}
		sign += ((*txt == '+') || (*txt == '-' ));
		txt++;
	}
	if (sign > 1)
	{
		error_bad_int_txt(s, errmsg);
		return (0);
	}
	return (ft_atoi(s));
}

void	chunk_init_vec3(t_vec3 *v, t_chunk *d, char **errmsg)
{
	vec3_init_values(v, trans_atof(d->param[X], errmsg),
		trans_atof(d->param[Y], errmsg), trans_atof(d->param[Z], errmsg));
}

void	chunk_init_color(t_color *c, t_chunk *d, char **errmsg)
{
	col_init_with_255(c, trans_atoi(d->param[X], errmsg),
		trans_atoi(d->param[Y], errmsg), trans_atoi(d->param[Z], errmsg));
}
