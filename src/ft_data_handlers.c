/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:03:04 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/07 20:48:30 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// printf("*nbrs[%d] ==? *nbrs[%d]\n", *nbrs[i], *nbrs[j]);
int	has_repeated_elements(int *nbrs, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nbrs[i] == nbrs[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	input_validation(int argc, char **argv, t_ps *ps)
{
	int	i;
	int	*nbrs;
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
		ft_free(nbrs);
		return (set_error(e_has_repeated_nbrs, ps));
	}
	ps->nbrs_non_normalized = nbrs;
	return (true);
}

/**
 * 	i = -1;
 * printf("NON NORMALIZED!!!\n");
 * while (++i < ps->nbrs_len)
 * 	printf("nbrs[%d] = %d\n", i, ps->nbrs_non_normalized[i]);
 * printf("\n\n");
 *
 * 	i = -1;
 * printf("NORMALIZED!!!\n");
 * while (++i < ps->nbrs_len)
 * 	printf("nbrs[%d] = %d\n", i, ps->nbrs[i]);
 * printf("\n\n");
 **/
int	nbrs_normalization(t_ps *ps)
{
	int	i;
	int	j;
	int	index;
	int	*nbrs;

	nbrs = malloc(sizeof(int) * ps->nbrs_len);
	if (!nbrs)
		return (set_error(e_mem_allocation, ps));
	i = -1;
	while (++i < ps->nbrs_len)
	{
		j = -1;
		index = 0;
		while (++j < ps->nbrs_len)
			if (ps->nbrs_non_normalized[i] > ps->nbrs_non_normalized[j])
				index++;
		nbrs[i] = index;
	}
	ps->nbrs = nbrs;
	return (true);
}
