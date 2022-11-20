/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:35:30 by rfelicio          #+#    #+#             */
/*   Updated: 2022/11/19 22:37:13 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	p(t_stack **origin, t_stack **target);

int	pa(t_stack **a, t_stack **b)
{
	if (!*b || !p(b, a))
		return (false);
	ft_putendl_fd("pa", 1);
	return (true);
}

int	pb(t_stack **a, t_stack **b)
{
	if (!*a || !p(a, b))
		return (false);
	ft_putendl_fd("pb", 1);
	return (true);
}

int	p(t_stack **origin, t_stack **target)
{
	t_stack	*fst;

	fst = *origin;
	*origin = fst->next;
	fst->next = NULL;
	ft_stack_add_front(target, fst);
	return (true);
}
