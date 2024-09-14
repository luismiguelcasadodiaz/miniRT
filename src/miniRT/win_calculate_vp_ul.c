/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_calculate_vp_ul.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:09:47 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/14 13:21:28 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
/* ************************************************************************** */
/* vp_x kcamera center - (0, 0, focal_lenge) - vp_y/2 -vp_y/	              */
/* ************************************************************************** */
void	win_calculate_vp_and_pd(t_win *w)
{
	w->vp_x = vec3_new();
	vec3_init_values(w->vp_x, w->vp->x, 0, 0);
	w->vp_y = vec3_new();
	vec3_init_values(w->vp_y, 0, -w->vp->y, 0);
	w->pd_x = vec3_new();
	vec3_div(w->pd_x, w->vp_x, w->size->x);
	w->pd_y = vec3_new();
	vec3_div(w->pd_y, w->vp_y, w->size->y);
}

/* ************************************************************************** */
/* vp_ul = camera center - (0, 0, focal_lenge) - vp_y/2 -vp_y/	              */
/* ************************************************************************** */
void	win_calculate_vp_ul(t_win *w)
{
	t_vec3	*aux;

	aux = vec3_new();
	vec3_init_values(aux, 0, 0, FOCAL_LENGTH);
	w->vp_ul = vec3_new();
	vec3_init_values(w->vp_ul, w->cc->x, w->cc->y, w->cc->z);
	vec3_sub(w->vp_ul, w->vp_ul, aux);
	vec3_div(aux, w->vp_x, 2);
	vec3_sub(w->vp_ul, w->vp_ul, aux);
	vec3_div(aux, w->vp_y, 2);
	vec3_sub(w->vp_ul, w->vp_ul, aux);
	vec3_free(aux);
}

/* ************************************************************************** */
/* pixel00  = view port Upper lef + 0.5 *(pixel delta x + pixel delta y)      */
/* ************************************************************************** */
void	win_calculate_pix00(t_win *w)
{
	w->pixel00 = vec3_new();
	vec3_add(w->pixel00, w->pd_x, w->pd_y);
	vec3_div(w->pixel00, w->pixel00, 2);
	vec3_add(w->pixel00, w->pixel00, w->vp_ul);
}
