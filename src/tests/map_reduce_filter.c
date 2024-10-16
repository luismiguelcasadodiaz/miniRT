/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reduce_filter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:42:01 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/16 19:00:04 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_reduce_filter.h"
#include <stdlib.h>
#include <stdio.h>

t_node	*node_new(int the_data, t_node *the_next)
{
	t_node	*self;

	self = (t_node *)malloc(sizeof(t_node));
	if (!self)
		return (NULL);
	self->data = the_data;
	self->next = the_next;
	return (self);
}

void	node_free(t_node *self)
{
	if (self)
	{
		node_free(self->next);
		free(self);
	}
}

int	apply(t_safp func, int x)
{
	return ((*func)(x));
}

t_node	*map(t_safp func, t_node *list)
{
	int	valor;

	if (!list)
		return (0);
	valor = (*func)(list->data);
	return (node_new(valor, map(func, list->next)));
}

t_node	*filter(t_safp func, t_node *lista)
{
	if (!lista)
		return (NULL);
	if ((*func)(lista->data))
		return (node_new(lista->data, filter(func, lista->next)));
	else
		return (filter(func, lista->next));
}

int	reduce(t_dafp func, int acc, t_node *lista)
{
	int	my_acc;

	if (!lista)
		return (acc);
	my_acc = (*func)(lista->data, acc);
	return (reduce(func, my_acc, lista->next));
}

int	sumatres(int num)
{
	return (num + 3);
}

int	dobla(int num)
{
	return (num * 2);
}

int	acuatro(int num)
{
	if (num > 0)
		return (4);
	else
		return (4);

}

int	espar(int num)
{
	return ((num % 2) == 0);
}

int	mayorquedos(int num)
{
	return ((num > 2));
}

int	suma(int a, int b)
{
	return (a + b);
}

int	sumadiezveces(int a, int b)
{
	return (a + 10 * b);
}

void	print_list(t_node *lista)
{
	if (lista)
	{
		printf(" %d, ", lista->data);
		print_list(lista->next);
	}
	else
		printf("\n");
}

int	main(void)
{
	t_node	*li;
	t_node	*listamastres;
	t_node	*listadoblada;
	t_node	*listaacuatro;
	t_node	*listapares;
	t_node	*listamayores;

	li = node_new(1, node_new(2, node_new(3, node_new(4, node_new(5, NULL)))));
	print_list(li);
	listamastres = map(sumatres, li);
	print_list(listamastres);
	listadoblada = map(dobla, li);
	print_list(listadoblada);
	listaacuatro = map(acuatro, li);
	print_list(listaacuatro);
	listapares = filter(espar, listamastres);
	print_list(listapares);
	listamayores = filter(mayorquedos, li);
	print_list(listamayores);
	printf("la suma de li es %d\n", reduce(suma, 0, li));
	node_free(li);
	node_free(listamastres);
	node_free(listadoblada);
	node_free(listaacuatro);
	node_free(listapares);
	node_free(listamayores);
}
