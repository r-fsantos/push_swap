/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 08:50:29 by rfelicio          #+#    #+#             */
/*   Updated: 2022/11/19 20:22:17 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_new_node(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

t_stack	*get_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = NULL;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = get_last_node(*stack);
	last->next = new;
}

// TODO: Add error handling layer
void	ft_fill_stack(t_stack **stack, int *nbrs, int len)
{
	int		i;
	t_stack	*new;

	i = -1;
	while (++i < len)
	{
		new = ft_new_node(nbrs[i]);
		ft_stack_add_back(stack, new);
	}
}

int	ft_stack_size(t_stack **stack)
{
	int		size;
	t_stack	*node;

	if (!*stack)
		return (0);
	size = 1;
	node = *stack;
	while (node->next)
	{
		node = node->next;
		size++;
	}
	return (size);
}
