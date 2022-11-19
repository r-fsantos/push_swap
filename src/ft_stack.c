/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 08:50:29 by rfelicio          #+#    #+#             */
/*   Updated: 2022/11/19 19:58:46 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	stacks_allocation(t_ps *ps)
{
	ps->stacks_are_heap_allocated = true;
	ps->stack_a = (t_stack **)ft_calloc(ps->nbrs_len + 1, sizeof(t_stack **));
	if (!ps->stack_a)
		return (set_error(e_mem_allocation, ps));
	ps->stack_b = (t_stack **)ft_calloc(ps->nbrs_len + 1, sizeof(t_stack **));
	if (!ps->stack_b)
		return (set_error(e_mem_allocation, ps));
	return (true);
}

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

