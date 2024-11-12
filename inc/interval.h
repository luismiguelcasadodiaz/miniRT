/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:32:35 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 11:27:25 by luicasad         ###   ########.fr       */
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
t_interval	*int_new(void);
void		int_free(t_interval *self);
void		int_init(t_interval *self, double min, double max);
void		int_init_empty(t_interval *self);
void		int_init_universe(t_interval *self);
//interval_setters.c
void		int_set_min(t_interval *self, double min);
void		int_set_max(t_interval *self, double max);
//interval_getters.c
double		int_get_min(t_interval *self);
double		int_get_max(t_interval *self);
//interval_methods.c
double		int_size(t_interval *self);
bool		int_contains(t_interval *self, double x);
bool		int_sorrounds(t_interval *self, double x);
void		int_expand(t_interval *self, double delta);
double		int_clamp(t_interval *self, double x);
//interval_methods_two.c
void		int_copy(t_interval *dest, t_interval *orig);
void		int_print(t_interval *self);
#endif
