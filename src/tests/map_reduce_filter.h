/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reduce_filter.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:42:01 by luicasad          #+#    #+#             */
/*   Updated: 2024/10/15 21:12:07 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

t_node	*node_new(int data, t_node *next);
void	node_free(t_node *self);

/*define signature for a single argument function pointer*/
typedef int	(*t_safp)(int numa);
/*define signature for a double argument function pointer */
//typedef int	(*t_dafp)(int numa, t_node *lista);
typedef int	(*t_dafp)(int numa, int num);

int		apply(t_safp func, int x);
int		sumatres(int num);
int		dobla(int num);
int		acuatro(int num);
int		espar(int num);
int		mayorquedos(int num);
int		suma(int a, int b);
int		sumadiezveces(int a, int b);
t_node	*map(t_safp func, t_node *list);
t_node	*filter(t_safp func, t_node *list);
int		reduce(t_dafp func, int acc, t_node *list);
