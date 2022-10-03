/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:21:21 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/03 20:22:33 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (!ft_ps_init(argc, argv, &ps))
		ft_error(&ps);
	if (!input_validating(argc, argv, &ps))
		ft_error(&ps);
	ft_putendl_fd("not error!", 1);
	return (0);
}
