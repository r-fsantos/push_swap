/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:21:21 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/03 10:03:49 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/**
 * TODO: Validation steps
 * 		- is_number
 * 		- <= MAX_INT
 * 		- ?
 * 		- has_repeated_elements?
 **/
int	main(int argc, char **argv)
{
	int		i;
	t_ps	ps;

	i = 0;
	printf("%s\n", argv[0]);
	while (argv[++i])
		printf("|%s|\n", argv[i]);
	if (!input_validating(argc, argv, &ps))
		ft_error(&ps);
	printf("not error\n");
	return (0);
}
