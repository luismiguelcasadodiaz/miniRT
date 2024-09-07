/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:19:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/06 12:56:06 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

void	show_usage(void)
{
	printf("USAGE:./miniRT <filename>\n");
	printf("WHERE:<filename> is a *.rt txt file with scene description.\n");
	return ;
}
