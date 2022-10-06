/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:49:02 by rfelicio          #+#    #+#             */
/*   Updated: 2022/10/06 13:49:27 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	**ft_malloc_nbrs(int args, t_ps *ps)
{
	int	**nbrs;
	int	i;

	nbrs = (int **)ft_calloc(args + 1, sizeof(*nbrs));
	if (!nbrs)
		return (NULL);
	i = -1;
	while (++i < args)
	{
		nbrs[i] = (int *)ft_calloc(1, sizeof(int));
		if (!nbrs[i])
		{
			ft_doublefree_size((void **)nbrs, i);
			ps->fl_error = e_mem_allocation;
			return (NULL);
		}
	}
	return (nbrs);
}
