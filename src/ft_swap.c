/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:00:47 by rfelicio          #+#    #+#             */
/*   Updated: 2022/11/19 21:13:28 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		s(t_stack **stack);
void	ft_swap_nbrs(int *a, int *b);

int	sa(t_stack **a)
{
	if (!s(a))
		return (false);
	ft_putendl_fd("sa", 1);
	return (true);
}

int	sb(t_stack **b)
{
	if (!s(b))
		return (false);
	ft_putendl_fd("sb", 1);
	return (true);
}

int	ss(t_stack **a, t_stack **b)
{
	if (!s(a) || !s(b))
		return (false);
	ft_putendl_fd("ss", 1);
	return (true);
}

int	s(t_stack **stack)
{
	t_stack	*fst;
	t_stack	*snd;

	if (!*stack || ft_stack_size(stack) < 2)
		return (false);
	fst = *stack;
	snd = fst->next;
	ft_swap_nbrs(&(fst->nbr), &(snd->nbr));
	return (true);
}

void	ft_swap_nbrs(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
