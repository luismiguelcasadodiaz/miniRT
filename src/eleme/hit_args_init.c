/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_args_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:11:01 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/02 11:27:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eleme.h"

// shadow does not require shadow_color  malloc
t_hit_args	*hit_args_new_s(void)
{
	t_hit_args	*self;

	self = (t_hit_args *)malloc(sizeof(t_hit_args));
	self->rec = hitrecord_new();
	self->ran = int_new();
	self->ray = ray_new();
	return (self);
}

void	hit_args_free_s(t_hit_args *self)
{
	hitrecord_free(self->rec);
	int_free(self->ran);
	ray_free(self->ray);
	free(self);
}

t_hit_args	*hit_args_new_l(void)
{
	t_hit_args	*self;

	self = (t_hit_args *)malloc(sizeof(t_hit_args));
	self->rec = hitrecord_new();
	self->ran = int_new();
	self->shadow_col = col_new();
	return (self);
}

void	hit_args_free_l(t_hit_args *self)
{
	hitrecord_free(self->rec);
	int_free(self->ran);
	col_free(self->shadow_col);
	free(self);
}
