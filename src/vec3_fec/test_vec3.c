/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:53:34 by luicasad          #+#    #+#             */
/*   Updated: 2024/09/08 10:21:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <sys/time.h>
#include <stdio.h>
#define OPS 10000000

static long	my_now_ms(void)
{
	struct timeval	s;
	long			ms;

	gettimeofday(&s, NULL);
	ms = (s.tv_sec * 1000) + (s.tv_usec / 1000);
	return (ms);
}

int	main(void)
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;
	int		n;
	long	t0_ms;
	long	t1_ms;

	vec3_init_values(&a, 1111.111, 2222.222, 3333.333);
	vec3_init_values(&b, 4444.444, 5555.555, 6666.666);
	vec3_print(&a);
	vec3_print(&b);
	c = vec3_add(a, b);
	vec3_print(&c);
	n = OPS;
	t0_ms = my_now_ms();
	while (n--)
		vec3_add(a, b);
	t1_ms = my_now_ms();
	printf("%d sums  take %*ld ms\n", OPS, 5, t1_ms - t0_ms); 
	n = OPS;
	t0_ms = my_now_ms();
	while (n--)
		vec3_sub(a, b);
	t1_ms = my_now_ms();
	printf("%d subs  take %*ld ms\n", OPS, 5, t1_ms - t0_ms); 
	n = OPS;
	t0_ms = my_now_ms();
	while (n--)
		vec3_mul(a, b);
	t1_ms = my_now_ms();
	printf("%d mult  take %*ld ms\n", OPS, 5, t1_ms - t0_ms); 
	n = OPS;
	t0_ms = my_now_ms();
	while (n--)
		vec3_dot(a, b);
	t1_ms = my_now_ms();
	printf("%d dots  take %*ld ms\n", OPS, 5, t1_ms - t0_ms); 
	n = OPS;
	t0_ms = my_now_ms();
	while (n--)
		vec3_cross(a, b);
	t1_ms = my_now_ms();
	printf("%d cross take %*ld ms\n", OPS, 5, t1_ms - t0_ms);
	return (0);
}
