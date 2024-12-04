/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_key_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:19:34 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/06 13:44:02 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

int	win_h_key_up(int keysym, t_win *data)
{
	if (data->win_ptr == NULL)
		printf("%d, NULL POINTER", keysym);
	return (0);
}
//	printf("Key_up: %d\n", keysym);
