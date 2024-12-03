/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ext_randr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 01:16:56 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/05 01:32:40 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include <unistd.h>
#include <X11/extensions/Xrandr.h>

/* global for independant extension */

RRMode	saved_mode = 0;

int	mlx_ext_fullscreen(t_xvar *xvar, t_win_list *win, int fullscreen)
{
	XWindowAttributes	watt;
	int					i;
	int					j;
	XRRScreenResources	*res;
	XRROutputInfo		*o_info;
	XRRCrtcInfo			*crtc;
	RRMode				mode_candidate;
	int					idx_output;
	int					idx_candi;

	if (!XGetWindowAttributes(xvar->display, win->window, &watt))
		return (0);
	res = XRRGetScreenResources(xvar->display, xvar->root);
	o_info = NULL;
	idx_output = -1;
	i = res->noutput;
	while (i--)
	{
		o_info = XRRGetOutputInfo(xvar->display, res, res->outputs[i]);
		if (o_info->connection == RR_Connected)
		{
			idx_output = i;
			i = 0;
		}
		else
			XRRFreeOutputInfo(o_info);
	}
	if (!o_info)
	{
		XRRFreeScreenResources(res);
		return (0);
	}
	idx_candi = -1;
	i = o_info->nmode;
	while (i--)
	{
		j = res->nmode;
		while (j--)
			if (res->modes[j].id == o_info->modes[i])
				if (res->modes[j].width >= watt.width
					&& res->modes[j].height >= watt.height
					&& (idx_candi == -1
						|| res->modes[idx_candi].width > res->modes[j].width
						|| res->modes[idx_candi].height > res->modes[j].height))
					idx_candi = i;
	}
	if (idx_candi < 0)
	{
		XRRFreeOutputInfo(o_info);
		XRRFreeScreenResources(res);
		return (0);
	}
	if (!fullscreen && saved_mode == -1)
		idx_candi = 0; /* if no clue, uses first mode, usually part of npreferred */
	mode_candidate = o_info->modes[idx_candi];
	if (!fullscreen)
		mode_candidate = saved_mode;
	crtc = XRRGetCrtcInfo(xvar->display, res, o_info->crtc);
	saved_mode = crtc->mode;
	i = XRRSetCrtcConfig(xvar->display, res, o_info->crtc, CurrentTime,
			0, 0, mode_candidate, crtc->rotation, &res->outputs[idx_output], 1);
	if (fullscreen)
		printf("found mode : %d x %d\n Status %d\n",
			res->modes[idx_candi].width,
			res->modes[idx_candi].height, i);
	else
		printf("back previous mode\n");
	XMoveWindow(xvar->display, win->window, 0, 0);
	XMapRaised(xvar->display, win->window);
	if (fullscreen)
		XGrabKeyboard(xvar->display, win->window, False,
			GrabModeAsync, GrabModeAsync, CurrentTime);
	else
	{
		XUngrabPointer(xvar->display, CurrentTime);
		XUngrabKeyboard(xvar->display, CurrentTime);
	}
	XSync(xvar->display, False);
	sleep(1);
	XRRFreeCrtcInfo(crtc);
	XRRFreeOutputInfo(o_info);
	XRRFreeScreenResources(res);
}
