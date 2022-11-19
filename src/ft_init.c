/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:00:12 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/14 10:12:16 by rfelicio         ###   ########.fr       */
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
