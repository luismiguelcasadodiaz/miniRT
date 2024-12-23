/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:16:32 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/13 16:58:59 by luicasad         ###   ########.fr       */
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

// returns a a random number in range min..max
// rand() returns integer and RAND_MAX is integer 
// that generartes zero at integer division ale/ RAND_MAX
// this is way i cast rand to float
float	ft_rand(float min, float max)
{
	float	result;
	double	ale;

	ale = (double)rand();
	result = min + (max - min) * (ale / RAND_MAX);
	return (result);
}
