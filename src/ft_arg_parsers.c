/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_parsers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:32:11 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/03 20:40:53 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	are_all_arguments_numbers(int argc, char **argv, t_ps *ps)
{
	ft_putchar_fd(argc + 48, 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd(argv[0], 1);
	ps->fl_error = false;
	return (true);
}

int	nbrs_are_in_valid_range(int argc, char **argv, t_ps *ps)
{
	argc += 0;
	ft_putendl_fd(argv[0], 1);
	ps->fl_error = false;
	return (true);
}
