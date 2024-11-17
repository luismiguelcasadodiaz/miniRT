/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camer_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:32:35 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/08 00:17:23 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camer.h"
#include <stdio.h>

void	camer_print(t_camer	*self)
{
	printf("-------------------------------------------\n");
	printf("id                       = CAMERA\n");
	printf("coor                     = ");
	vec3_print(&self->coor);
	printf("novec                    = ");
	vec3_print(&self->novec);
	printf("Horizontal Field of view = %f\n", self->hfov);
	printf("Vertical   Field of view = %f\n", self->vfov);
	printf("Aspect ratio             = %f\n", self->aspect_ratio);
	printf("Image width              = %d\n", self->image_width);
	printf("Image heigth             = %d\n", self->image_height);
	printf("samples per pixel        = %d\n", self->samples_per_pixel);
	printf("Max depth                = %d\n", self->max_depth);
	printf("Defocus angel            = %f\n", self->defocus_angle);
	printf("Focus disctance          = %f\n", self->focus_dist);
	printf("Defocus radius           = %f\n", self->defocus_radius);
	printf("Pixel sample scales      = %f\n", self->pixel_samples_scale);
	printf("Focal length             = %f\n", self->focal_lenght);
	printf("theta                    = %f\n", self->theta);
	printf("h                        = %f\n", self->h);
	printf("Viewport width           = %f\n", self->viewport_width);
	printf("Viewport heigth          = %f\n", self->viewport_height);
	printf("Camera lookfrom          = ");
	point_print(&self->lookfrom);
	printf("Camera lookat            = ");
	point_print(&self->lookat);
	printf("vup                      = ");
	vec3_print(&self->vup);
	printf("Viewport                 = ");
	point_print(&self->vport);
	printf("Center                   = ");
	point_print(&self->center),
	printf("pixel00                  = ");
	point_print(&self->pixel00_loc);
	printf("pd_x                     = ");
	vec3_print(&self->pd_u);
	printf("pd_y                     = ");
	vec3_print(&self->pd_v);
	printf("u                        = ");
	vec3_print(&self->u);
	printf("v                        = ");
	vec3_print(&self->v);
	printf("w                        = ");
	vec3_print(&self->w);
	printf("defocus disk u           = ");
	vec3_print(&self->defocus_disk_u);
	printf("defocus disk u           = ");
	vec3_print(&self->defocus_disk_v);
	printf("vp_x                     = ");
	vec3_print(&self->vp_u);
	printf("vp_y                     = ");
	vec3_print(&self->vp_v);
	printf("vp_ul                    = ");
	vec3_print(&self->vp_ul);
	printf("Color start              = ");
	col_print(&self->color_start);
	printf("Color End                = ");
	col_print(&self->color_end);
}
