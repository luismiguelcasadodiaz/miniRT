/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 09:32:27 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/19 11:25:38 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <float.h>

int	main(void)
{
	printf("DBL_MAX %lf\n\n", DBL_MAX);
	printf("DBL_MIN %lf\n\n", DBL_MIN);
	printf("-DBL_MAX %lf\n\n", -DBL_MAX);
	printf("DBL_MAX %2.4e\n\n", DBL_MAX);
	printf("DBL_MIN %1.5e\n\n", DBL_MIN);
	printf("-DBL_MAX %3.3e\n\n", -DBL_MAX);
}

