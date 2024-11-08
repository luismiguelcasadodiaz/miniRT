/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:11:26 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/01 09:11:51 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include <stdlib.h>
#include <stdio.h>
/* chunk_print() prints line by line each chunk member*/
void	chunk_print(t_chunk *chunks)
{
    size_t  i;

    i = 0;
    printf("This chunk has %ld elements\n", chunks->num);
    while (i < chunks->num)
        printf("%s\n", chunks->param[i++]);
}
