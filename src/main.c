/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:21:21 by rfelicio          #+#    #+#             */
/*   Updated: 2022/11/19 21:18:46 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (!ft_ps_init(argc, argv, &ps))
		ft_error(&ps);
	if (!input_validation(argc, argv, &ps))
		ft_error(&ps);
	if (!nbrs_normalization(&ps))
		ft_error(&ps);
	if (!stacks_allocation(&ps))
		ft_error(&ps);
	ft_fill_stack(ps.stack_a, ps.nbrs, ps.nbrs_len);
	ft_free((void *)ps.nbrs_non_normalized);
	ft_free((void *)ps.nbrs);
	if (ps.stacks_are_heap_allocated)
	{
		ft_doublefree_size((void **)ps.stack_a, ps.nbrs_len);
		ft_doublefree_size((void **)ps.stack_b, ps.nbrs_len);
	}
	ft_putendl_fd("\nREMOVE THIS MSG!\nFinished without any error!", 1);
	return (0);
}
