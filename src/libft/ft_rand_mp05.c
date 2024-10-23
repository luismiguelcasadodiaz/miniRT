/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:16:32 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/23 19:24:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*// returns a a random numbre in range -1 .. 1
float	ft_rand_mp1(void)
{
	int	half_rand_max;

	half_rand_max = RAND_MAX / 2;
	return ((rand() - half_rand_max) / half_rand_max);
}
*/

// returns a a random numbre in range -0.5 .. 0.5
float	ft_rand_mp05(void)
{
	int	half_rand_max;

	half_rand_max = RAND_MAX / 2;
	return (((rand() - half_rand_max) / half_rand_max) / 2);
}
