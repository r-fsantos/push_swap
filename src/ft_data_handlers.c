/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:03:04 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/06 19:00:26 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// static int	has_repeated_elements(int **nbrs, t_ps *ps)
// {
// 	// verificar !nbrs || !*nbrs
// 		// return (set_error(...))
// 	// encontrou elemento repetido
// 	// desaloca que foi alocado e retorna falso
// 	// se estiver no caminho feliz, retorna true
// }

/**
 * TODO: rename to is_valid_input
 * TODO: has_repeated_elements? -> bubble sort
 **/
int	input_validating(int argc, char **argv, t_ps *ps)
{
	int	i;
	int	**nbrs;

	i = 1;
	while (i < argc)
		if (!is_number(argv[i++], ps))
			return (false);
	i = 1;
	nbrs = get_nbrs_from(argc - 1, &argv[1], ps);
	if (!nbrs || !*nbrs)
		return (false);
	// if (has_repeated_elements(nbr))
		// deallocate nbrs
		// set error
		// return false
	// guarda elementos para posterior normalização
	return (true);
}
