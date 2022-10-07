/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:03:04 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/06 23:31:14 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// printf("*nbrs[%d] ==? *nbrs[%d]\n", *nbrs[i], *nbrs[j]);
int	has_repeated_elements(int **nbrs, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (*nbrs[i] == *nbrs[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

/**
 * TODO: rename to is_valid_input
 **/
int	input_validating(int argc, char **argv, t_ps *ps)
{
	int	i;
	int	**nbrs;
	int	nbrs_len;

	i = 1;
	while (i < argc)
		if (!is_number(argv[i++], ps))
			return (false);
	nbrs_len = ps->nbrs_len;
	nbrs = get_nbrs_from(&argv[1], nbrs_len, ps);
	if (!nbrs || !*nbrs)
		return (false);
	if (has_repeated_elements(nbrs, nbrs_len))
	{
		ft_doublefree_size((void **)nbrs, nbrs_len);
		return (set_error(e_has_repeated_nbrs, ps));
	}
	ps->nbrs_non_normalized = nbrs;
	return (true);
}
