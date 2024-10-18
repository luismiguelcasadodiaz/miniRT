/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:32:35 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/18 21:03:05 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERVAL_H
# define INTERVAL_H
# include <stdbool.h>

typedef struct s_interval
{
	double	min;
	double	max;
}	t_interval;

//interval_init.c
t_interval	*interval_new(void);
void		interval_init(t_interval *self, double min, double max);
void		interval_init_empty(t_interval *self);
void		interval_init_universe(t_interval *self);
void		interval_copy(t_interval *dest, t_interval *orig);
//interval_setters.c
void		interval_set_min(t_interval *self, double min);
void		interval_set_max(t_interval *self, double max);
//interval_getters.c
double		interval_get_min(t_interval *self);
double		interval_get_max(t_interval *self);
//interval_methods.c
double		interval_size(t_interval *self);
bool		interval_contains(t_interval *self, double x);
bool		interval_sorrounds(t_interval *self, double x);
void		interval_expand(t_interval *self, double delta);
double		interval_clamp(t_interval *self, double x);

#endif
