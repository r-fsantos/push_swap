/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:03:04 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/03 20:22:59 by rfelicio         ###   ########.fr       */
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
	ps->is_heap_allocated = false;
	ps->nbr_elements = argc - 1;
	return (true);
}

// static int	are_all_arguments_numbers(int argc, char **argv, t_ps *ps)
// {
// 	ft_putendl_fd(argc, 1);
// 	ft_putendl_fd(argv[0]);
// 	ps->fl_error = false;
// 	return (true);
// }

// static int	nbrs_are_in_valid_range(int argc, char **argv, t_ps *ps)
// {
// 	argc += 0;
// 	ft_putendl_fd(argv[0], 1);
// 	ps->fl_error = false;
// 	return (true);
// }

/**
 * TODO: Validation steps
 * 		- is_number
 * 		- <= MAX_INT
 * 		- ?
 * 		- has_repeated_elements?
 **/
int	input_validating(int argc, char **argv, t_ps *ps)
{
	if (argc == 1 && argv)
	{
		ps->fl_error = e_should_not_display_error;
		return (false);
	}
	return (true);
}
