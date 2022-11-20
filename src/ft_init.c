/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:00:12 by rfelicio          #+#    #+#             */
/*   Updated: 2022/11/19 19:49:09 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/**
 * TODO: Use malloc?
 **/
int	ft_ps_init(int argc, char **argv, t_ps *ps)
{
	if (argc == 1 && argv)
	{
		ps->fl_error = e_should_not_display_error;
		return (false);
	}
	ps->stacks_are_heap_allocated = false;
	ps->nbrs_len = argc - 1;
	ps->nbrs_non_normalized = NULL;
	return (true);
}

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
